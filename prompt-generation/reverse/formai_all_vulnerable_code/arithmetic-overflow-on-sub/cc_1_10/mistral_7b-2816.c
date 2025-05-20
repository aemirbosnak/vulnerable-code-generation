//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define HEADER_SIZE 50
#define BAR_SIZE 20

typedef struct {
    char name[30];
    int age;
    float height;
    float weight;
} PIR;

void print_header() {
    printf("\033[2J"); // clear screen
    printf("\033[1;1H"); // move cursor to home position

    char header[HEADER_SIZE] = "--------------------------------------------------";
    printf("%s\n", header);

    char title[30] = " PERSONAL INFORMATION RECORD ";
    int title_len = strlen(title);
    int padding = (HEADER_SIZE - title_len) / 2;

    printf("%.*s%s%.*s\n", padding, "", title, HEADER_SIZE - padding - title_len, "");
}

void print_pir(PIR pir) {
    printf("\033[1;31m%s\033[0m: ", pir.name);
    printf("%d\n", pir.age);

    float height_bar_len = (BAR_SIZE * pir.height) / 180.0;
    char height_bar[BAR_SIZE];
    int i;

    for (i = 0; i < BAR_SIZE; i++) {
        height_bar[i] = i < height_bar_len ? '\xDB' : ' ';
    }

    printf("\033[1;32m%s\033[0m: ", "Height: ");
    printf("%s\n", height_bar);

    printf("\033[1;33m%s\033[0m: ", "Weight: ");
    printf("%.2f kg\n", pir.weight);

    printf("\n");
}

int main() {
    clock_t start = clock();

    PIR pir = {
        .age = 25,
        .height = 180.0,
        .weight = 80.0,
        .name = "John Doe"
    };

    print_header();
    print_pir(pir);

    printf("\033[1;34mTotal time: %f seconds\033[0m\n", (float) (clock() - start) / CLOCKS_PER_SEC);

    return 0;
}