//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 30
#define PATTERN_COUNT 10

void generate_pattern(int pattern_num) {
    int i, j;
    switch (pattern_num) {
        case 1:
            for (i = 0; i < MAX_ROWS; i++) {
                for (j = 0; j < MAX_COLS; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
        case 2:
            for (i = 0; i < MAX_ROWS; i++) {
                for (j = 0; j < MAX_COLS; j++) {
                    printf("%d", rand() % 10);
                }
                printf("\n");
            }
            break;
        case 3:
            for (i = 0; i < MAX_ROWS; i++) {
                for (j = 0; j < MAX_COLS; j++) {
                    printf("%c", 'A' + (rand() % 26));
                }
                printf("\n");
            }
            break;
        case 4:
            for (i = 0; i < MAX_ROWS; i++) {
                for (j = 0; j < MAX_COLS; j++) {
                    printf("%c", 'a' + (rand() % 26));
                }
                printf("\n");
            }
            break;
        case 5:
            for (i = 0; i < MAX_ROWS; i++) {
                for (j = 0; j < MAX_COLS; j++) {
                    printf("%c", 'A' + (rand() % 26));
                }
            }
            break;
        default:
            printf("Invalid pattern number\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    int pattern_num;

    printf("Enter pattern number (1-10): ");
    scanf("%d", &pattern_num);

    generate_pattern(pattern_num);

    return 0;
}