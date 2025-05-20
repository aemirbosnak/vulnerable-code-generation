#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10
#define LINE_SIZE 256

char lines[MAX_LINES][LINE_SIZE];
int num_lines = 0;

void print_menu() {
    printf("\nText Editor\n");
    printf("1. New File\n");
    printf("2. Load File\n");
    printf("3. Save File\n");
    printf("4. Exit\n");
}

void new_file() {
    int i;
    for (i = 0; i < num_lines; i++) {
        memset(lines[i], 0, LINE_SIZE);
    }
    num_lines = 0;
}

void input_line(int index) {
    char input[LINE_SIZE];
    printf("Enter line %d: ", index + 1);
    fgets(input, LINE_SIZE, stdin);
    strcpy(lines[index], input);
}

void display_lines() {
    int i;
    for (i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
    }
}

int main() {
    int choice;
    while (1) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                new_file();
                break;
            case 2:
                // Implement loading a file here (without bounds checking)
                break;
            case 3:
                // Implement saving a file here (without bounds checking)
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
        num_lines++;
        input_line(num_lines - 1);
        display_lines();
    }
    return 0;
}
