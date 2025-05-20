//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char text[MAX_FORTUNE_LENGTH + 1];
} fortune;

void load_fortunes(fortune *fortunes) {
    FILE *file = fopen("fortunes.txt", "r");
    int count = 0;

    if (file == NULL) {
        printf("Error: Could not open fortunes file.\n");
        exit(1);
    }

    while (fscanf(file, "%s\n", fortunes[count].text)!= EOF && count < MAX_FORTUNES) {
        count++;
    }

    fclose(file);
}

fortune *get_random_fortune(fortune *fortunes) {
    int index = rand() % MAX_FORTUNES;
    return &fortunes[index];
}

int main() {
    setbuf(stdout, NULL);

    srand(time(NULL));

    fortune fortunes[MAX_FORTUNES];
    load_fortunes(fortunes);

    printf("Welcome to the Automated Fortune Teller!\n\n");

    while (1) {
        fortune *selected_fortune = get_random_fortune(fortunes);
        printf("%s\n", selected_fortune->text);

        char choice;
        printf("Would you like another fortune? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    return 0;
}