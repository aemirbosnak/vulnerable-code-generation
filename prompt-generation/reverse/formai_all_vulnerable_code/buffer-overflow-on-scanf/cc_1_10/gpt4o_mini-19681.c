//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXPEERS 10
#define MAX_FILENAME 256
#define BUFFER_SIZE 1024

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int port;
} Peer;

typedef struct {
    Peer peers[MAXPEERS];
    int peer_count;
} PeerList;

void add_peer(PeerList *plist, const char *ip, int port) {
    if (plist->peer_count < MAXPEERS) {
        strncpy(plist->peers[plist->peer_count].ip, ip, INET_ADDRSTRLEN);
        plist->peers[plist->peer_count].port = port;
        plist->peer_count++;
    }
}

void list_peers(PeerList *plist) {
    printf("Current peers in the network:\n");
    for (int i = 0; i < plist->peer_count; i++) {
        printf("%d: %s:%d\n", i+1, plist->peers[i].ip, plist->peers[i].port);
    }
}

void send_file(const char *filename, const char *ip, int port) {
    int sock;
    struct sockaddr_in server_addr;
    FILE *file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if ((file = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        return;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        fclose(file);
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        fclose(file);
        return;
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        send(sock, buffer, bytes_read, 0);
    }

    printf("File %s sent to %s:%d\n", filename, ip, port);
    
    fclose(file);
    close(sock);
}

void receive_file(int port, const char *output_filename) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    FILE *file;
    ssize_t bytes_received;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        return;
    }

    listen(server_sock, 3);

    printf("Waiting for incoming connections on port %d...\n", port);
    
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_len);
    if (client_sock < 0) {
        perror("Accept failed");
        close(server_sock);
        return;
    }

    if ((file = fopen(output_filename, "wb")) == NULL) {
        fprintf(stderr, "Could not open file %s for writing.\n", output_filename);
        close(client_sock);
        close(server_sock);
        return;
    }

    while ((bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }

    printf("File received and saved as %s\n", output_filename);
    
    fclose(file);
    close(client_sock);
    close(server_sock);
}

int main() {
    PeerList peer_list = {0};
    int choice;

    while (1) {
        printf("\n=== Decentralized File Sharing ===\n");
        printf("1. Add Peer\n");
        printf("2. List Peers\n");
        printf("3. Send File\n");
        printf("4. Receive File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1: {
                char ip[INET_ADDRSTRLEN];
                int port;
                printf("Enter peer IP: ");
                fgets(ip, INET_ADDRSTRLEN, stdin);
                ip[strcspn(ip, "\n")] = 0; // Remove newline
                printf("Enter peer Port: ");
                scanf("%d", &port);
                add_peer(&peer_list, ip, port);
                break;
            }
            case 2:
                list_peers(&peer_list);
                break;
            case 3: {
                char filename[MAX_FILENAME];
                char peer_ip[INET_ADDRSTRLEN];
                int peer_port;
                printf("Enter filename to send: ");
                fgets(filename, MAX_FILENAME, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                printf("Enter peer IP: ");
                fgets(peer_ip, INET_ADDRSTRLEN, stdin);
                peer_ip[strcspn(peer_ip, "\n")] = 0; // Remove newline
                printf("Enter peer Port: ");
                scanf("%d", &peer_port);
                send_file(filename, peer_ip, peer_port);
                break;
            }
            case 4: {
                char output_filename[MAX_FILENAME];
                printf("Enter filename to save received file: ");
                fgets(output_filename, MAX_FILENAME, stdin);
                output_filename[strcspn(output_filename, "\n")] = 0; // Remove newline
                receive_file(PORT, output_filename);
                break;
            }
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}