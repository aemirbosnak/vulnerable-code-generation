//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

bool is_safe(char *str) {
    size_t len = strlen(str);
    int i;

    for(i = 0; i < len; i++) {
        if(isalnum(str[i])) continue;
        if(str[i] == ' ' || str[i] == '\n') continue;
        if(str[i] == ';' && str[i+1] == ' ') continue; // allow semicolon space for funny messages
        return false;
    }

    return true;
}

void sanitize(char *str) {
    size_t len = strlen(str);
    int i, j;

    for(i = j = 0; i < len; i++) {
        if(!isalnum(str[i])) {
            if(i != len-1) { // don't overwrite the null terminator
                memmove(str+i+1, str+i, len-i);
                len += 1;
            }
            i--; // re-evaluate the current character
            continue;
        }
        str[j++] = str[i];
    }
    str[j] = '\0';
}

int main(void) {
    char input[1024];
    int fd;

    printf("Hello there, kind traveler!\n");
    printf("Please enter a funny and safe string for me to print out loud:\n");

    if(gets(input) != NULL) {
        if(is_safe(input)) {
            sanitize(input);
            printf("You said: %s\n", input);
            printf("Let me read that again...\n");

            fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            write(fd, input, strlen(input)+1);
            close(fd);

            printf("I've written your funny string to output.txt for safekeeping!\n");
        } else {
            printf("Sorry, %s is not safe for me to print out loud. Try again.\n", input);
        }
    } else {
        printf("Uh oh, it seems you've disappeared!\n");
    }

    return 0;
}