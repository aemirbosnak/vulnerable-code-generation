//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(void) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char filename[BUFFER_SIZE];

    printf("Welcome to the Shape-Shifting FTP Client!\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR: Failed to open socket.\n");
        return 1;
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(21);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("ERROR: Failed to connect to server.\n");
        return 1;
    }

    // Shape-shifting mode start!
    bool is_flamingo_mode = false;
    bool is_giraffe_mode = false;

    printf("You are currently in normal mode. Type 'flamingo' to transform into Flamingo mode, or type 'giraffe' to transform into Giraffe mode.\n");

    while (true) {
        printf("ftp> ");

        bzero(buffer, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE - 1, stdin);

        if (strncmp(buffer, "quit", 4) == 0) {
            printf("Goodbye!\n");
            break;
        }

        if (is_flamingo_mode) {
            printf("FLAMINGO: I'm a flamingo!\n");

            if (strncmp(buffer, "dance", 5) == 0) {
                printf("FLAMINGO: Oh yeah, time to dance!\n");
                write(sockfd, "STOR dance.mp3\n", 15);

                FILE* fp = fopen("dance.mp3", "rb");
                if (!fp) {
                    printf("ERROR: Unable to open dance.mp3.\n");
                    continue;
                }

                while (true) {
                    int nread = fread(buffer, 1, sizeof(buffer), fp);
                    if (nread > 0) {
                        write(sockfd, buffer, nread);
                    }

                    if (nread < BUFFER_SIZE) {
                        if (feof(fp))
                            printf("FLAMINGO: Dance complete!\n");
                        if (ferror(fp))
                            printf("FLAMINGO: ERROR: Failed to read dance.mp3.\n");
                        break;
                    }
                }

                fclose(fp);
                continue;
            }
        }

        if (is_giraffe_mode) {
            printf("GIRAFFE: I'm a giraffe!\n");

            if (strncmp(buffer, "stretch", 7) == 0) {
                printf("GIRAFFE: Stretching my neck...\n");
                write(sockfd, "STOR stretch.txt\n", 17);

                FILE* fp = fopen("stretch.txt", "w");
                if (!fp) {
                    printf("ERROR: Unable to open stretch.txt.\n");
                    continue;
                }

                fprintf(fp, "          /\\_/\\\n"
                            "         / o o \\\n"
                            "        (   \"   )\n"
                            "         \\~(*)~/\n"
                            "          / _ \\ \n"
                            "         ( ( ) )\n"
                            "          \\___/\n");

                fclose(fp);
                printf("GIRAFFE: Stretch complete!\n");
                continue;
            }
        }

        if (strncmp(buffer, "flamingo", 8) == 0) {
            printf("You transformed into Flamingo mode!\n");
            is_giraffe_mode = false;
            is_flamingo_mode = true;
            continue;
        }

        if (strncmp(buffer, "giraffe", 7) == 0) {
            printf("You transformed into Giraffe mode!\n");
            is_giraffe_mode = true;
            is_flamingo_mode = false;
            continue;
        }

        if (strncmp(buffer, "ls", 2) == 0) {
            printf("ftp> ls\n");
            write(sockfd, "LIST\n", 5);

            FILE* fp = fopen("ls.txt", "w");
            if (!fp) {
                printf("ERROR: Unable to open ls.txt.\n");
                continue;
            }

            while (true) {
                int nread = read(sockfd, buffer, sizeof(buffer));
                if (nread < 0) {
                    printf("ERROR: Failed to read from server.\n");
                    break;
                }
                if (nread == 0)
                    break;

                fwrite(buffer, 1, nread, fp);
            }

            fclose(fp);
            system("cat ls.txt");
            system("rm ls.txt");
            continue;
        }

        if (strncmp(buffer, "get", 3) == 0) {
            sscanf(buffer, "%s %s", command, filename);
            printf("ftp> get %s\n", filename);

            char get_command[BUFFER_SIZE];
            sprintf(get_command, "RETR %s\n", filename);
            write(sockfd, get_command, strlen(get_command));

            FILE* fp = fopen(filename, "wb");
            if (!fp) {
                printf("ERROR: Unable to open %s for writing.\n", filename);
                continue;
            }

            while (true) {
                int nread = read(sockfd, buffer, sizeof(buffer));
                if (nread < 0) {
                    printf("ERROR: Failed to read from server.\n");
                    break;
                }
                if (nread == 0)
                    break;

                fwrite(buffer, 1, nread, fp);
            }

            fclose(fp);
            printf("ftp> get %s complete!\n", filename);
            continue;
        }

        printf("ftp> Command not recognized.\n");
    }

    close(sockfd);
    return 0;
}