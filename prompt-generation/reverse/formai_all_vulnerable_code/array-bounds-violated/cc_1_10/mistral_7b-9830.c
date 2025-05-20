//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_FORTUNE_LEN 10
#define MAX_FORTUNE_LEN 50

typedef struct {
    char *fortune;
    int len;
    struct fortune *next;
} fortune;

fortune *fortunes = NULL;

void generate_fortune(int len) {
    char letter = 'A' + (rand() % 26);
    char fortune_str[MAX_FORTUNE_LEN];

    if (len <= 0) {
        printf("Empty fortune.\n");
        return;
    }

    fortune_str[len - 1] = letter;
    fortune_str[len] = '\0';

    if (len == 1) {
        fortune *new_fortune = (fortune *)malloc(sizeof(fortune));
        new_fortune->len = 1;
        new_fortune->fortune = (char *)malloc(sizeof(char) * (len + 1));
        new_fortune->fortune[len] = letter;
        new_fortune->next = fortunes;
        fortunes = new_fortune;
        printf("%c\n", letter);
        return;
    }

    generate_fortune(len - 1);
    printf("%c", letter);
    fortune *new_fortune = (fortune *)malloc(sizeof(fortune));
    new_fortune->len = len;
    new_fortune->fortune = (char *)malloc(sizeof(char) * (len + 1));
    strncpy(new_fortune->fortune, fortune_str, len + 1);
    new_fortune->next = fortunes;
    fortunes = new_fortune;
}

int main() {
    srand(time(NULL));

    printf("Enter the length of your fortune: ");
    int fortune_len;
    scanf("%d", &fortune_len);

    if (fortune_len < MIN_FORTUNE_LEN || fortune_len > MAX_FORTUNE_LEN) {
        printf("Invalid fortune length. Please enter a length between %d and %d.\n", MIN_FORTUNE_LEN, MAX_FORTUNE_LEN);
        return 1;
    }

    generate_fortune(fortune_len);

    fortune *current = fortunes;

    while (current != NULL) {
        printf("%s\n", current->fortune);
        fortune *temp = current;
        current = current->next;
        free(temp->fortune);
        free(temp);
    }

    return 0;
}