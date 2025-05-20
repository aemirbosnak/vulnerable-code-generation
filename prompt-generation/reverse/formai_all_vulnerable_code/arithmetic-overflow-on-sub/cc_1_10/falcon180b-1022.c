//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_LINE 1024
#define PORT 21

void die(char *msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

char *get_line(FILE *fp)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, fp)) == -1)
        die("getline() failed");

    if (line[read - 1] == '\n')
        line[--read] = '\0';

    return line;
}

char *get_word(char *line)
{
    char *word = line;

    while (isspace(*word))
        word++;

    char *end = word + strlen(word) - 1;

    while (isspace(*end))
        end--;

    *(end + 1) = '\0';

    return word;
}

int main(int argc, char *argv[])
{
    if (argc!= 4)
        die("Usage:./ftp_client <server_ip> <username> <password>");

    char *server_ip = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    struct hostent *host;

    if ((host = gethostbyname(server_ip)) == NULL)
        die("gethostbyname() failed");

    int sock = socket(PF_INET, SOCK_STREAM, 0);

    if (sock == -1)
        die("socket() failed");

    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        die("connect() failed");

    fprintf(stdout, "Connected to %s:%d\n", server_ip, PORT);

    char *user_pass = malloc(strlen(username) + strlen(password) + 3);

    if (user_pass == NULL)
        die("malloc() failed");

    sprintf(user_pass, "%s:%s", username, password);

    send(sock, user_pass, strlen(user_pass), 0);

    free(user_pass);

    while (1) {
        char *line = get_line(stdin);

        if (strcmp(line, "quit") == 0) {
            send(sock, line, strlen(line), 0);
            break;
        }

        send(sock, line, strlen(line), 0);

        char *reply = get_line(stdout);

        if (reply == NULL)
            die("getline() failed");

        fprintf(stdout, "%s\n", reply);
    }

    close(sock);

    return 0;
}