//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 1000000

int n; // number of items
int s[MAX_VAL]; // size of each item
int v[MAX_VAL]; // value of each item
int f[MAX_VAL]; // flag indicating if item is taken or not

void input() {
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the size and value of each item:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s[i], &v[i]);
    }
}

void print_solution() {
    int total_size = 0;
    int total_value = 0;

    printf("Selected items:\n");

    for (int i = 0; i < n; i++) {
        if (f[i]) {
            printf("Item %d - size: %d, value: %d\n", i+1, s[i], v[i]);
            total_size += s[i];
            total_value += v[i];
        }
    }

    printf("Total size: %d, Total value: %d", total_size, total_value);
}

void greedy() {
    int remaining = MAX_VAL;
    float ratio[MAX_VAL];
    float max_ratio;
    int max_index;

    for (int i = 0; i < n; i++) {
        ratio[i] = (float)v[i] / (float)s[i];
    }

    while (remaining > 0) {
        max_ratio = 0.0;
        max_index = -1;

        for (int i = 0; i < n; i++) {
            if (f[i] == 0 && ratio[i] > max_ratio) {
                max_ratio = ratio[i];
                max_index = i;
            }
        }

        if (max_index == -1) {
            break;
        }

        if (remaining >= s[max_index]) {
            f[max_index] = 1;
            remaining -= s[max_index];
        } else {
            f[max_index] = (float)remaining / (float)s[max_index];
            remaining = 0;
        }
    }
}

int main() {
    input();
    greedy();
    print_solution();

    return 0;
}