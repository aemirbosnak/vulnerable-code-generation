//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef struct {
    char string[100];
    int length;
} StringData;

void print_string(StringData data) {
    for (int i = 0; i < data.length; ++i) {
        putchar(data.string[i]);
        fflush(stdout);
        usleep(50000);
    }
    putchar('\n');
}

int main() {
    int total_chars = 0;
    int total_time = 0;
    int num_tests = 10;
    int test_length = 40;
    StringData strings[num_tests];

    srand(time(NULL));

    for (int i = 0; i < num_tests; ++i) {
        strings[i].length = test_length;
        strings[i].string[0] = '\0';

        for (int j = 0; j < test_length; ++j) {
            strings[i].string[j] = 'A' + rand() % 26;
            total_chars++;
        }

        strings[i].string[test_length] = '\0';
    }

    clock_t start, end;

    for (int i = 0; i < num_tests; ++i) {
        start = clock();
        print_string(strings[i]);
        fflush(stdout);

        getchar();

        end = clock();
        total_time += (int)(end - start);
    }

    double wpm = (double)total_chars * 60 / total_time;

    printf("Typing speed: %.2f characters per minute\n", wpm);

    return 0;
}