//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888

struct knight {
    char name[50];
    char message[100];
};

int main() {
    int sock;
    struct sockaddr_in server, client;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct knight knight;
        scanf("%s %s", knight.name, knight.message);

        if (strcmp(knight.name, "Sir") == 0) {
            printf("Greetings, Sir %s! What is thy bidding?\n", knight.message);
        } else if (strcmp(knight.name, "Lady") == 0) {
            printf("Hail, Lady %s! Thy beauty doth captivate me! What is thy desire?\n", knight.message);
        } else {
            printf("Hark! Who art thou, %s? Thy presence is most unexpected! Speak thy mind, if thou dost desire to communicate.\n", knight.name);
        }
    }

    close(sock);
    return 0;
}