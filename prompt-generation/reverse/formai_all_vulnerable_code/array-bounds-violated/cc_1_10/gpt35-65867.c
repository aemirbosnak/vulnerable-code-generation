//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include <stdio.h>
#include <string.h>

void print_line(char line[], char ch) {
    int len = strlen(line);

    for (int i = 0; i < len; i++) {
        if (line[i] == ' ') {
            printf(" ");
        }
        else {
            printf("%c", ch);
        }
    }
    printf("\n");
}

void print_ascii(char string[]) {
    char ch[] = "|\\/|>(-)<(-)<>";
    int len = strlen(string);

    for (int i = 0; i < len; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            printf("%c ", ch[string[i] - 'A']);
        }
        else if (string[i] >= 'a' && string[i] <= 'z') {
            printf("%c ", ch[string[i] - 'a']);
        }
        else {
            printf("  ");
        }
    }
    printf("\n");
}

int main() {
    char message[100];
    char line1[100], line2[100], line3[100], line4[100], line5[100], line6[100], line7[100], line8[100], line9[100], line10[100];

    printf("Enter the message to be converted to ASCII art:\n");
    fgets(message, sizeof(message), stdin);

    // Removing the newline character from the message
    message[strlen(message) - 1] = '\0';

    // Creating the ASCII art lines
    sprintf(line1, "%s", "/\\/\\");
    sprintf(line2, "%s", "\\    /");
    sprintf(line3, "%s", " )  ( ");
    sprintf(line4, "%s", "/    \\");
    sprintf(line5, "%s", "|    |");
    sprintf(line6, "%s", "|    |");
    sprintf(line7, "%s", "|    |");
    sprintf(line8, "%s", "\\    /");
    sprintf(line9, "%s", " \\__/ ");
    sprintf(line10, "%s", "       ");

    // Printing the ASCII art
    print_line(line1, '_');
    print_ascii(message);
    print_line(line2, ' ');
    print_line(line3, ' ');
    print_line(line4, '-');
    print_line(line5, '|');
    print_line(line6, '|');
    print_line(line7, '|');
    print_line(line8, '-');
    print_line(line9, '_');
    print_line(line10, ' ');
    return 0;
}