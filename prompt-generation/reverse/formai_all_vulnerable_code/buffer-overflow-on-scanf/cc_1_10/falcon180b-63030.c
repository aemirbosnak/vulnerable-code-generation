//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SYMBOLS 100
#define MAX_HISTORY_SIZE 1000

typedef struct {
    char symbol[10];
    double price;
    time_t date;
} History;

int main() {
    int numSymbols;
    char symbols[MAX_SYMBOLS][10];
    int i;

    printf("Enter the number of symbols to track: ");
    scanf("%d", &numSymbols);

    for (i = 0; i < numSymbols; i++) {
        printf("Enter symbol %d: ", i+1);
        scanf("%s", symbols[i]);
    }

    while (1) {
        printf("Enter the symbol to get history for: ");
        scanf("%s", symbols[0]);

        History history[MAX_HISTORY_SIZE];
        int numHistory = 0;

        // Get history for the symbol
        FILE *file = fopen("history.txt", "r");
        if (file == NULL) {
            printf("No history available\n");
        } else {
            while (fscanf(file, "%s %lf %ld\n", history[numHistory].symbol, &history[numHistory].price, &history[numHistory].date)!= EOF) {
                if (strcmp(symbols[0], history[numHistory].symbol) == 0) {
                    printf("Date: %s, Price: $%.2lf\n", ctime(&history[numHistory].date), history[numHistory].price);
                }
                numHistory++;
                if (numHistory >= MAX_HISTORY_SIZE) {
                    break;
                }
            }
            fclose(file);
        }

        printf("Enter 1 to save current price and date to history file\n");
        scanf("%d", &i);
        if (i == 1) {
            time_t now = time(NULL);
            History newHistory;
            strcpy(newHistory.symbol, symbols[0]);
            newHistory.price = 0.0; // Replace with actual price
            newHistory.date = now;

            file = fopen("history.txt", "a");
            if (file!= NULL) {
                fprintf(file, "%s %lf %ld\n", newHistory.symbol, newHistory.price, newHistory.date);
                fclose(file);
                printf("Price and date saved to history file\n");
            } else {
                printf("Error saving to history file\n");
            }
        }
    }

    return 0;
}