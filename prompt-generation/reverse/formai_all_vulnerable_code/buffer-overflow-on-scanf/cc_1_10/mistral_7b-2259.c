//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: medieval
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX 1000

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void print_primes(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int start, end;
    char command[100];

    printf("> Welcome, noble knight, to the Holy Grail of Prime Numbers!\n");
    printf("> Enter the starting and ending numbers, thou shalt find thy prime numbers therein:\n");
    printf("> ");
    scanf("%d %d", &start, &end);

    if (end < start) {
        printf("> Thou art mistaken, good knight, start must be less than end.\n");
        return 1;
    }

    print_primes(start, end);

    FILE *log_file = fopen("primes.log", "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    fprintf(log_file, "%d %d\n", start, end);
    fclose(log_file);

    printf("> Thy prime numbers have been revealed, noble knight. Thou art welcome to consult the sacred log file for further enlightenment.\n");

    return 0;
}