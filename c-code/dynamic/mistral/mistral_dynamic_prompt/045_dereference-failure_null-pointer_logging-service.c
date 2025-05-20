#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void log_message(const char *message) {
    int fd;
    char *log_file = "app.log";

    fd = open(log_file, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd < 0) {
        perror("Error opening log file");
        return;
    }

    char buffer[1024];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S ", tm_info);
    strcat(buffer, message);

    write(fd, buffer, strlen(buffer));
    close(fd);
}

int main() {
    char *user_message = NULL;
    int n;

    printf("Enter a message: ");
    n = getline(&user_message, &n, stdin);
    if (n <= 0) {
        printf("Error reading input\n");
        return 1;
    }

    log_message(user_message);

    free(user_message); // Don't forget to free the dynamically allocated memory
    printf("Message logged successfully\n");

    return 0;
}
