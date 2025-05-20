#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void edit_line(char *buffer, int line_number) {
    char new_line[MAX_LINE_LENGTH];
    printf("Enter new line: ");
    fgets(new_line, sizeof(new_line), stdin);
    if (line_number == 0) {
        strncpy(buffer, new_line, MAX_LINE_LENGTH - 1);
        buffer[MAX_LINE_LENGTH - 1] = '\0';
    } else {
        strcat(buffer, "\n");
        strncat(buffer, new_line, MAX_LINE_LENGTH - strlen(buffer) - 2);
    }
}

int main() {
    char file_content[1024 * 10]; // 10MB buffer
    int choice, line_number;

    while (1) {
        printf("\n1. Edit Line\n");
        printf("2. Print File Content\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left-over

        switch (choice) {
            case 1:
                printf("Enter line number to edit: ");
                scanf("%d", &line_number);
                edit_line(file_content, line_number);
                break;
            case 2:
                printf("File content:\n%s", file_content);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
