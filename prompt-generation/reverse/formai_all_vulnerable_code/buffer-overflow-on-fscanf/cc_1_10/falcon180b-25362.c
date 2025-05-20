//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 50

typedef struct {
    char fortune[100];
} fortune_t;

void load_fortunes(fortune_t fortunes[]) {
    FILE *file = fopen("fortunes.txt", "r");
    int count = 0;

    if (file == NULL) {
        printf("Error: Could not open fortunes file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", fortunes[count].fortune)!= EOF && count < MAX_FORTUNES) {
        count++;
    }

    fclose(file);
}

void generate_fortune(fortune_t fortunes[], int num_fortunes) {
    srand(time(NULL));
    int index = rand() % num_fortunes;

    printf("%s\n", fortunes[index].fortune);
}

int main() {
    fortune_t fortunes[MAX_FORTUNES];

    load_fortunes(fortunes);

    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("How many fortunes would you like to receive? ");
    scanf("%d", &num_fortunes);

    if (num_fortunes > MAX_FORTUNES) {
        printf("Sorry, I can only generate up to %d fortunes at a time.\n", MAX_FORTUNES);
        return 1;
    }

    for (int i = 0; i < num_fortunes; i++) {
        generate_fortune(fortunes, num_fortunes);
        printf("\n");
    }

    return 0;
}