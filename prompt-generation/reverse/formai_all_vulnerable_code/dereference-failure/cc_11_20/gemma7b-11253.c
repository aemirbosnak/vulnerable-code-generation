//Gemma-7B DATASET v1.0 Category: Palindrome Checker ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main()
{
    char buf[1024];
    char *pbuf = buf;
    int len = 0;
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));

    listen(sockfd, 10);

    while (1)
    {
        len = recv(sockfd, buf, sizeof(buf), 0);
        if (len < 0)
        {
            perror("Error receiving data");
            close(sockfd);
            exit(1);
        }

        pbuf = buf;
        while (len)
        {
            char *s = pbuf;
            int i = 0;
            for (; i < len && *s != '\0'; i++, s++)
            {
                if (*s == 'a' || *s == 'A')
                {
                    *s = 'A';
                }
                else if (*s == 'e' || *s == 'E')
                {
                    *s = 'E';
                }
                else if (*s == 'i' || *s == 'I')
                {
                    *s = 'I';
                }
                else if (*s == 'o' || *s == 'O')
                {
                    *s = 'O';
                }
                else if (*s == 'u' || *s == 'U')
                {
                    *s = 'U';
                }
            }

            len -= pbuf - buf;
            pbuf = buf + len;
        }

        send(sockfd, buf, len, 0);
    }

    close(sockfd);
    return 0;
}