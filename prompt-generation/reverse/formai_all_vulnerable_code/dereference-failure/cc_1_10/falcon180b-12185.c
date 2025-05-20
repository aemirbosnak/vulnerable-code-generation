//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_LENGTH 80

struct fortune {
    char text[MAX_LENGTH];
    int length;
};

void generate_fortunes() {
    FILE *fortunes_file = fopen("fortunes.txt", "w");
    if (fortunes_file == NULL) {
        printf("Error: Could not create fortunes file.\n");
        exit(1);
    }

    srand(time(NULL));

    int num_fortunes = rand() % MAX_FORTUNES + 1;

    for (int i = 0; i < num_fortunes; i++) {
        char fortune_text[MAX_LENGTH];
        snprintf(fortune_text, MAX_LENGTH, "Your future is %s.", rand() % 2? "bright" : "dark");
        struct fortune fortune = {.text = fortune_text,.length = strlen(fortune_text) };
        fwrite(&fortune, sizeof(fortune), 1, fortunes_file);
    }

    fclose(fortunes_file);
}

void tell_fortune(FILE *fortunes_file) {
    struct fortune fortune;
    if (fread(&fortune, sizeof(fortune), 1, fortunes_file)!= 1) {
        printf("Error: Could not read fortune.\n");
        exit(1);
    }

    printf("Your fortune: %s\n", fortune.text);
}

int main() {
    generate_fortunes();
    FILE *fortunes_file = fopen("fortunes.txt", "r");
    if (fortunes_file == NULL) {
        printf("Error: Could not open fortunes file.\n");
        exit(1);
    }

    tell_fortune(fortunes_file);

    fclose(fortunes_file);
    return 0;
}