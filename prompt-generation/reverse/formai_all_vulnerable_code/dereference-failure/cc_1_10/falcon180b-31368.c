//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char* text;
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES];
int num_fortunes;

void generate_fortunes() {
    char buffer[MAX_FORTUNE_LENGTH];
    FILE* file = fopen("fortunes.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open fortunes file.\n");
        exit(1);
    }

    while (fgets(buffer, MAX_FORTUNE_LENGTH, file)!= NULL) {
        int length = strlen(buffer);
        if (length > MAX_FORTUNE_LENGTH) {
            printf("Warning: Truncating fortune to %d characters.\n", MAX_FORTUNE_LENGTH);
            length = MAX_FORTUNE_LENGTH;
        }
        fortunes[num_fortunes].text = malloc(length + 1);
        strncpy(fortunes[num_fortunes].text, buffer, length);
        fortunes[num_fortunes].length = length;
        num_fortunes++;
    }

    fclose(file);
}

void print_fortune(int index) {
    printf("%s\n", fortunes[index].text);
}

int main() {
    srand(time(NULL));

    generate_fortunes();

    int choice;
    do {
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > num_fortunes) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice < 1 || choice > num_fortunes);

    print_fortune(choice - 1);

    return 0;
}