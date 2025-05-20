//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNE 100

struct fortune {
    char text[100];
};

void generate_fortunes() {
    FILE *f;
    char filename[20] = "fortunes.txt";
    struct fortune fortunes[MAX_FORTUNE];

    f = fopen(filename, "w");
    if (f == NULL) {
        printf("Error: Could not create file.\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_FORTUNE) {
        printf("Enter a fortune (leave blank to stop):\n");
        scanf("%s", fortunes[count].text);
        if (fortunes[count].text[0] == '\0') {
            break;
        }
        fprintf(f, "%s\n", fortunes[count].text);
        count++;
    }

    fclose(f);
}

void print_random_fortune() {
    char filename[20] = "fortunes.txt";
    FILE *f;
    struct fortune fortune;

    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    rewind(f);
    fscanf(f, "%s", fortune.text);
    printf("%s\n", fortune.text);

    fclose(f);
}

int main() {
    srand(time(NULL));

    generate_fortunes();

    while (1) {
        print_random_fortune();
        printf("Press enter to get another fortune or type 'quit' to exit:\n");
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
    }

    return 0;
}