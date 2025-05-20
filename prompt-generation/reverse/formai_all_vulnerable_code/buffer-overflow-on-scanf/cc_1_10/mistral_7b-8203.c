//MISTRAL-7B DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LEN 1024

void reverse_string(char *str, int len) {
    int i, j;
    char temp;

    for (i = 0, j = len - 1; i < len / 2; ++i, --j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char filename[MAX_LEN];
    char input_str[MAX_LEN];
    char output_str[MAX_LEN];
    int fd, ret;

    printf("Enter a file name: ");
    scanf("%s", filename);

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    ret = read(fd, input_str, MAX_LEN);
    if (ret < 0) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    close(fd);

    printf("Original String: %s\n", input_str);

    strcpy(output_str, input_str);
    reverse_string(output_str, strlen(output_str));

    printf("Reversed String: %s\n", output_str);

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error creating output file");
        return 1;
    }

    ret = write(fd, output_str, strlen(output_str));
    if (ret < 0) {
        perror("Error writing to output file");
        close(fd);
        return 1;
    }

    printf("Output written to output.txt\n");
    close(fd);

    return 0;
}