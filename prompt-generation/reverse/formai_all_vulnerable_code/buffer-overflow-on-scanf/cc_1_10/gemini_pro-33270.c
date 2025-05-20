//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>

struct tstp {
    char c;
    int count;
};

int main() {
    struct tstp tstp_arr[] = {
        {'a', 0},
        {'b', 0},
        {'c', 0},
        {'d', 0},
        {'e', 0},
        {'f', 0},
        {'g', 0},
        {'h', 0},
        {'i', 0},
        {'j', 0},
        {'k', 0},
        {'l', 0},
        {'m', 0},
        {'n', 0},
        {'o', 0},
        {'p', 0},
        {'q', 0},
        {'r', 0},
        {'s', 0},
        {'t', 0},
        {'u', 0},
        {'v', 0},
        {'w', 0},
        {'x', 0},
        {'y', 0},
        {'z', 0}
    };
    int tstp_size = sizeof(tstp_arr) / sizeof(tstp_arr[0]);
    char input_string[101];
    printf("Enter a string (max 100 characters): ");
    scanf("%s", input_string);
    for (int i = 0; input_string[i] != '\0'; i++) {
        char input_char = input_string[i];
        for (int j = 0; j < tstp_size; j++) {
            if (tstp_arr[j].c == input_char) {
                tstp_arr[j].count++;
                break;
            }
        }
    }
    printf("Typing Speed Test Results:\n");
    for (int i = 0; i < tstp_size; i++) {
        printf("%c:\t%d times\n", tstp_arr[i].c, tstp_arr[i].count);
    }
    return 0;
}