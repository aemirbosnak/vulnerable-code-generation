//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80
#define MAX_USER_INPUT_LENGTH 80

struct fortune {
    char text[MAX_FORTUNE_LENGTH];
    char author[MAX_FORTUNE_LENGTH];
};

void load_fortunes(struct fortune fortunes[MAX_FORTUNES]) {
    FILE *file;
    file = fopen("fortunes.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open fortunes.txt\n");
        exit(1);
    }
    int count = 0;
    while (fscanf(file, "%s %s\n", fortunes[count].text, fortunes[count].author)!= EOF) {
        count++;
        if (count >= MAX_FORTUNES) {
            break;
        }
    }
    fclose(file);
}

void get_user_input(char input[MAX_USER_INPUT_LENGTH]) {
    printf("What is your question? ");
    fgets(input, MAX_USER_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            input[i] = toupper(input[i]);
        }
    }
}

void generate_fortune(struct fortune fortunes[MAX_FORTUNES], char input[MAX_USER_INPUT_LENGTH]) {
    int index = rand() % MAX_FORTUNES;
    while (index == 0) {
        index = rand() % MAX_FORTUNES;
    }
    printf("Your fortune: %s\n", fortunes[index].text);
    printf("Author: %s\n", fortunes[index].author);
}

int main() {
    struct fortune fortunes[MAX_FORTUNES];
    load_fortunes(fortunes);
    char input[MAX_USER_INPUT_LENGTH];
    while (1) {
        get_user_input(input);
        generate_fortune(fortunes, input);
    }
    return 0;
}