#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void searchReplace(char *str, char *find, char *replace, int *position) {
    int i, lenFind = strlen(find), lenReplace = strlen(replace), lenStr = strlen(str);
    char temp[lenStr];

    for (i = 0; i < lenStr; i++) {
        temp[i] = (i + *position < lenStr) ? str[i + *position] : '\0';
        if (i + lenFind <= lenStr && strncmp(&temp[i], find, lenFind) == 0) {
            for (int j = i; j < i + lenFind; j++)
                temp[j] = str[j + *position + lenFind];
            for (int j = i + lenFind; j < lenStr - lenReplace + *position; j++)
                temp[j] = replace[j - (i + lenFind)];
            *position += lenReplace - lenFind;
        }
    }

    strcpy(str, temp);
}

int main() {
    char str[10], find[5], replace[5];
    int position = 0;

    printf("Enter a string: ");
    gets(str);
    printf("Enter the string to find: ");
    gets(find);
    printf("Enter the replacement string: ");
    gets(replace);

    searchReplace(str, find, replace, &position);
    printf("Modified string: %s\n", str);

    return 0;
}
