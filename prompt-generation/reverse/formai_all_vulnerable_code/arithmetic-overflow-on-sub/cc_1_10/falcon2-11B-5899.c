//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>

#define URL "http://example.com"
#define EMAIL "noreply@example.com"
#define EMAIL_SUBJECT "Website Status Notification"
#define EMAIL_BODY "The website %s is currently down.\n"

void send_email(const char *subject, const char *body) {
    char command[1000];
    snprintf(command, sizeof(command), "echo '%s' | mail -s '%s' %s", body, subject, EMAIL);
    system(command);
}

int main(int argc, char **argv) {
    char command[1000];
    snprintf(command, sizeof(command), "curl -s %s | grep -q 'HTTP/1.0 200 OK'", URL);
    pid_t pid = fork();
    if (pid == 0) {
        execlp("sh", "sh", "-c", command, NULL);
        exit(1);
    }
    else if (pid > 0) {
        waitpid(pid, NULL, 0);
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    while (1) {
        gettimeofday(&end, NULL);
        double uptime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

        if (uptime > 10) {
            send_email(EMAIL_SUBJECT, EMAIL_BODY);
            start = end;
        }
        sleep(1);
    }

    return 0;
}