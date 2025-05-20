//FormAI DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

#define MAX_PING_PACKET_SIZE    64
#define MAX_PING_PACKETS        5
#define MAX_PING_TIMEOUT_SEC    1

int main(int argc, char *argv[])
{
    char str[MAX_PING_PACKET_SIZE] = {0};
    int status = 0;
    pid_t pid;
    int pings = 0, i = 0;
    struct timeval tv[MAX_PING_PACKETS];
    double diff = 0, avg = 0;

    /* User input validation */
    if (argc != 2)
    {
        printf("Usage: %s <IP address>\n", argv[0]);
        return -1;
    }

    /* Ping loop */
    for (pings = 0; pings < MAX_PING_PACKETS; pings++)
    {
        pid = fork();

        if (pid < 0)
        {
            /* Error handling */
            printf("Error creating child process\n");
            return -1;
        }
        else if (pid == 0)
        {
            /* Child process */
            sprintf(str, "ping -c 1 -w %d %s", MAX_PING_TIMEOUT_SEC, argv[1]);
            execlp("/bin/sh", "/bin/sh", "-c", str, NULL);
            exit(0);
        }
        else
        {
            /* Parent process */
            waitpid(pid, &status, 0);
            gettimeofday(&tv[pings], NULL);
            printf("%d bytes from %s: icmp_seq=%d time=%lu ms\n",
                    MAX_PING_PACKET_SIZE, argv[1], pings,
                    (tv[pings].tv_sec * 1000 + tv[pings].tv_usec / 1000) -
                    (tv[pings - 1].tv_sec * 1000 + tv[pings - 1].tv_usec / 1000));
            fflush(stdout);
            sleep(1);
        }
    }

    /* Calculate average time */
    for (i = 1; i < MAX_PING_PACKETS; i++)
    {
        diff += (tv[i].tv_sec * 1000 + tv[i].tv_usec / 1000) - (tv[i - 1].tv_sec * 1000 + tv[i - 1].tv_usec / 1000);
    }
    avg = diff / (MAX_PING_PACKETS - 1);
    printf("\nAverage time: %0.2f ms\n", avg);

    return 0;
}