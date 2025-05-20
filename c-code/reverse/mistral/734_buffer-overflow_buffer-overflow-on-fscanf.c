#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 128

int main() {
    pid_t pid;
    int status;
    char buffer[BUFFER_SIZE];

    pid = fork();

    if (pid == -1) {
        perror("fork failed");
        return 1;
    } else if (pid > 0) {
        // Parent process
        close(pid);

        system("top -bn1 | awk '/Cpu(s):/ { print $3 }' > cpu_usage.txt");
        FILE *file = fopen("cpu_usage.txt", "r");
        fgets(buffer, BUFFER_SIZE, file);
        fclose(file);

        sscanf(buffer, "%f", &buffer[0]);
        printf("CPU usage: %f\n", buffer[0]);
    } else {
        // Child process
        execlp("top", "top", "-bn1", (char *)0);
        perror("execlp failed");
    }

    waitpid(pid, &status, 0);

    return 0;
}
