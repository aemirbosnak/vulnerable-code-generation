//Falcon-180B DATASET v1.0 Category: Email Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10
#define SERVER_PORT 8080
#define EMAIL_FILE "emails.txt"

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_socket, sd;
    int opt = 1;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    FILE *fp;
    char *content = NULL;
    size_t content_len = 0;
    char *subject = NULL;
    size_t subject_len = 0;
    char *sender = NULL;
    size_t sender_len = 0;
    char *recipient = NULL;
    size_t recipient_len = 0;
    time_t timestamp;

    if ((fp = fopen(EMAIL_FILE, "r")) == NULL) {
        printf("Error opening email file.\n");
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
        content = realloc(content, content_len + strlen(buffer) + 1);
        strncat(content, buffer, strlen(buffer));
        content_len += strlen(buffer);
    }

    fclose(fp);

    while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
        subject = realloc(subject, subject_len + strlen(buffer) + 1);
        strncat(subject, buffer, strlen(buffer));
        subject_len += strlen(buffer);

        while (isspace(*subject))
            subject++;
    }

    while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
        sender = realloc(sender, sender_len + strlen(buffer) + 1);
        strncat(sender, buffer, strlen(buffer));
        sender_len += strlen(buffer);

        while (isspace(*sender))
            sender++;
    }

    while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
        recipient = realloc(recipient, recipient_len + strlen(buffer) + 1);
        strncat(recipient, buffer, strlen(buffer));
        recipient_len += strlen(buffer);

        while (isspace(*recipient))
            recipient++;
    }

    fclose(fp);

    timestamp = time(NULL);
    printf("Email sent at %s\n", ctime(&timestamp));

    printf("From: %s\n", sender);
    printf("To: %s\n", recipient);
    printf("Subject: %s\n", subject);
    printf("Content:\n%s\n", content);

    return 0;
}