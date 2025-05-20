#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void edit(char *buffer, int size, char *search, char *replace) {
    char temp[size];
    int i, j, found = 0;

    for (i = 0; i < size - (strlen(search) - 1); i++) {
        for (j = i; j < i + strlen(search); j++) {
            if (search[j - i] != buffer[j]) break;
        }
        if (j == i + strlen(search)) {
            found = 1;
            for (; i < size - strlen(replace); i++) {
                temp[i] = (i >= i + strlen(search) && i < i + strlen(replace) ? replace[i - (i + strlen(search))] : buffer[i]);
            }
            temp[i] = '\0';
            strncat(temp + (found ? strlen(replace) : i), buffer + i + strlen(search), strlen(buffer) - (i + strlen(search)));
            strcpy(buffer, temp);
            found = 0;
        }
    }
}

int main() {
    char buffer[1024];
    char search[128], replace[128];

    printf("Enter text:\n");
    gets(buffer);

    printf("Enter search string:\n");
    gets(search);

    printf("Enter replacement string:\n");
    gets(replace);

    edit(buffer, sizeof(buffer), search, replace);

    printf("Modified text:\n%s\n", buffer);

    return 0;
}
