//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_SIZE 1024

int main() {
    int fd1[2], fd2[2];
    char buffer1[MAX_SIZE], buffer2[MAX_SIZE];
    char *token;
    int num1, num2, result;

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        printf("Pipe failed\n");
        exit(1);
    }

    printf("Enter the first number: ");
    scanf("%s", buffer1);
    num1 = atoi(buffer1);

    printf("Enter the second number: ");
    scanf("%s", buffer2);
    num2 = atoi(buffer2);

    printf("Enter the operation (+, -, *, /): ");
    scanf("%s", buffer1);
    token = strtok(buffer1, " ");
    if (strcmp(token, "+") == 0) {
        result = num1 + num2;
    } else if (strcmp(token, "-") == 0) {
        result = num1 - num2;
    } else if (strcmp(token, "*") == 0) {
        result = num1 * num2;
    } else if (strcmp(token, "/") == 0) {
        result = num1 / num2;
    } else {
        printf("Invalid operation\n");
        exit(1);
    }

    sprintf(buffer1, "%d", result);
    write(fd1[1], buffer1, strlen(buffer1));
    close(fd1[1]);

    read(fd2[0], buffer2, MAX_SIZE);
    printf("Result: %s\n", buffer2);

    close(fd1[0]);
    close(fd2[1]);
    return 0;
}