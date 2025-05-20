//MISTRAL-7B DATASET v1.0 Category: Smart home light control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SMART_HOME_API_PORT 12345
#define MAX_BUFFER_SIZE 256

void print_menu() {
    printf("\n------------------- Smart Home Light Control -------------------\n");
    printf("1. Turn on light\n");
    printf("2. Turn off light\n");
    printf("3. Change brightness\n");
    printf("4. Exit\n");
}

int main() {
    int socket_desc, read_size;
    struct sockaddr_in server;
    char buffer[MAX_BUFFER_SIZE];

    if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Could not create socket");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(SMART_HOME_API_PORT);

    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connect failed");
        return 1;
    }

    print_menu();

    while (1) {
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                send(socket_desc, "turn_on\0", strlen("turn_on\0"), 0);
                break;
            case 2:
                send(socket_desc, "turn_off\0", strlen("turn_off\0"), 0);
                break;
            case 3: {
                int brightness;
                printf("Enter the brightness level (0-100): ");
                scanf("%d", &brightness);
                sprintf(buffer, "change_brightness %d\0", brightness);
                send(socket_desc, buffer, strlen(buffer), 0);
                break;
            }
            case 4:
                close(socket_desc);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                print_menu();
                break;
        }

        read_size = recv(socket_desc, buffer, MAX_BUFFER_SIZE, 0);
        printf("%s\n", buffer);
    }

    close(socket_desc);
    return 0;
}