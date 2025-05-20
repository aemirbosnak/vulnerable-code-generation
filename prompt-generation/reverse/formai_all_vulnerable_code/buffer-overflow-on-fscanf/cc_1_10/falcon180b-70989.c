//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 1000

struct fortune {
    char text[80];
    char category[20];
};

void load_fortunes(struct fortune fortunes[MAX_FORTUNES]) {
    FILE *file = fopen("fortunes.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open fortunes file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", fortunes[count].text, fortunes[count].category) == 2) {
        count++;
        if (count == MAX_FORTUNES) {
            printf("Error: Too many fortunes in file.\n");
            exit(1);
        }
    }

    fclose(file);
}

void tell_fortune(struct fortune fortunes[MAX_FORTUNES]) {
    system("clear");
    printf("Welcome to the Automated Fortune Teller!\n\n");

    time_t now = time(NULL);
    srand(now);
    int random_index = rand() % MAX_FORTUNES;

    printf("Your fortune:\n\n");
    printf("%s\n", fortunes[random_index].text);
    printf("Category: %s\n\n", fortunes[random_index].category);

    printf("Press enter to exit...\n");
    getchar();
}

int main() {
    struct fortune fortunes[MAX_FORTUNES];

    load_fortunes(fortunes);
    tell_fortune(fortunes);

    return 0;
}