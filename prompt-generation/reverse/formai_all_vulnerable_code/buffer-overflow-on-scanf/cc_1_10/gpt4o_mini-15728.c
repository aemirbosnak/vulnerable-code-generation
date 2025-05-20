//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw_fiber(int n) {
    // Draw the Fibonacci numbers in a stylized manner
    for (int i = 1; i <= n; i++) {
        char line[50];
        snprintf(line, sizeof(line), "Fibonacci(%d): ", i);
        
        int padding = 20 - strlen(line);
        if (padding < 0) padding = 0;

        // Print space padding for alignment
        printf("%s", line);
        for (int j = 0; j < padding; j++) {
            printf(" ");
        }
        
        // Calculate Fibonacci number
        unsigned long long a = 0, b = 1, fib;
        if (i == 1) {
            fib = a;
        } else if (i == 2) {
            fib = b;
        } else {
            for (int j = 3; j <= i; j++) {
                fib = a + b;
                a = b;
                b = fib;
            }
        }

        // Display the Fibonacci number
        printf("%llu\n", fib);
    }
}

void medieval_intro() {
    // Styled introductory text
    printf("========================================\n");
    printf("    Welcome to the Enchanted Fibonacci  \n");
    printf("             Sequence Visualizer       \n");
    printf("    Where Numbers Dance in Harmony!    \n");
    printf("========================================\n");
    printf("\n");
}

void medieval_outro() {
    // Styled closing text
    printf("========================================\n");
    printf("        Huzzah! Thus ends our quest!  \n");
    printf("           May your numbers grow!     \n");
    printf("========================================\n");
}

int main() {
    int number_of_terms;
    
    medieval_intro();
    
    printf("Pray, enter the number of terms thou wishest to behold (up to 20): ");
    scanf("%d", &number_of_terms);

    if (number_of_terms > 20 || number_of_terms < 1) {
        printf("\nAlas! Only up to 20 terms can be conjured!\n");
        return 1;
    }

    // Behold the Fibonacci sequence with thy chosen number of terms
    draw_fiber(number_of_terms);
    
    medieval_outro();

    return 0;
}