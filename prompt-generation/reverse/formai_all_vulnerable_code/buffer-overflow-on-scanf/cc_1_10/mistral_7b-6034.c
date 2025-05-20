//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER 32
#define LINE_LENGTH 80

void decimal_to_binary(int decimal, char binary[MAX_NUMBER]);
void print_love_letter(int number, char binary[MAX_NUMBER]);

int main(void) {
    int number;
    char binary[MAX_NUMBER];

    printf("From your humble servant,\n");
    printf("Romeo, to his beloved Juliet,\n");
    printf("I present to you a token,\n");
    printf("A secret message, veiled in binary,\n");

    scanf("%d", &number);

    if (number >= 0 && number <= pow(2, MAX_NUMBER)) {
        decimal_to_binary(number, binary);
        print_love_letter(number, binary);
    } else {
        printf("Error: Number out of range.\n");
        return 1;
    }

    printf("\nFrom your devoted,\n");
    printf("Romeo.\n");

    return 0;
}

void decimal_to_binary(int decimal, char binary[MAX_NUMBER]) {
    int i = 0;

    memset(binary, '0', MAX_NUMBER);

    while (decimal > 0) {
        binary[i] = decimal % 2 + '0';
        decimal /= 2;
        i++;
    }
}

void print_love_letter(int number, char binary[MAX_NUMBER]) {
    int i;
    char line[LINE_LENGTH];

    printf("\nBehold, fair Juliet,\n");
    printf("The binary form of your number,\n");
    printf("A gift from me to thee,\n");
    printf("A beacon in the darkness of this digital world:\n");

    for (i = 0; i < MAX_NUMBER; i++) {
        if (i > 0 && i % 8 == 0) {
            strcat(line, "\n");
        }
        if (i < MAX_NUMBER - 1) {
            strcat(line, " ");
        }
        strcat(line, &binary[i]);
    }

    printf("%s\n", line);
}