//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void convert_to_upper(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

void convert_to_lower(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

int main() {
    char color_code[MAX_LENGTH];
    char color_name[MAX_LENGTH];
    int i = 0;
    while (i < MAX_LENGTH) {
        printf("Enter a color code (e.g. #FF0000): ");
        scanf("%s", color_code);
        if (strcmp(color_code, "") == 0) {
            printf("Error: Color code cannot be empty.\n");
            i = 0;
            continue;
        }
        if (strcmp(color_code, "#") == 0) {
            printf("Error: Color code must start with a valid hexadecimal character.\n");
            i = 0;
            continue;
        }
        if (strlen(color_code)!= 7) {
            printf("Error: Color code must be exactly 7 characters long.\n");
            i = 0;
            continue;
        }
        for (int j = 0; j < strlen(color_code); j++) {
            if (!isxdigit(color_code[j])) {
                printf("Error: Color code must only contain hexadecimal characters.\n");
                i = 0;
                continue;
            }
        }
        strcpy(color_name, "Color: ");
        convert_to_upper(color_name);
        strcat(color_name, color_code);
        printf("%s\n", color_name);
        i++;
    }
    return 0;
}