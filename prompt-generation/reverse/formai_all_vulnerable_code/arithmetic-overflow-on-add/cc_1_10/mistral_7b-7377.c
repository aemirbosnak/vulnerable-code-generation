//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#define MAX_SIZE 1000
#define COMMA ","
#define NEWLINE "\n"
#define TAB "\t"
#define ARROW " -> "
#define LABEL "[label ="
#define STYLE "style=\"fill:#008000; font-size:12pt; font-family:Verdana; text-anchor:middle;\" "
#define PRINTF printf

typedef struct {
    char symbol[5];
    int price;
} Stock;

bool read_csv(const char *filename, Stock stocks[MAX_SIZE]) {
    FILE *file = fopen(filename, "r");
    int i = 0;

    if (file == NULL) {
        PRINTF("Error: Unable to open file \"%s\"\n", filename);
        return false;
    }

    while (fgets(stocks[i].symbol, sizeof(stocks[i].symbol), file) != NULL) {
        sscanf(stocks[i].symbol, "%s%n", stocks[i].symbol, &i);
        i++;

        if (fgets(stocks[i].symbol + strlen(stocks[i].symbol), sizeof(stocks[i].symbol) - strlen(stocks[i].symbol), file) != NULL && isdigit(stocks[i].symbol[strlen(stocks[i].symbol)])) {
            sscanf(stocks[i].symbol + strlen(stocks[i].symbol) - strlen(COMMA) + 1, "%d%n", &stocks[i].price, &i);
            i++;
            stocks[i].symbol[i] = '\0';
        } else {
            PRINTF("Error: Invalid format for stock %d\n", i);
            return false;
        }

        i++;
    }

    fclose(file);
    return true;
}

void print_graphviz_header() {
    PRINTF("digraph StockMarket {\n");
    PRINTF("rankdir = LR;\n");
    PRINTF("node [shape = rectangle, width = 1, height = 0.5, fontsize = 12, fontname = \"Verdana\", fontcolor = white, fillcolor = black, style = \"filled\"];\n");
}

void print_graphviz_stock(Stock stock) {
    PRINTF(LABEL "%s" STYLE "[labeljust = c, x = %d, y = %d];\n", stock.symbol, -strlen(stock.symbol) / 2, -strlen(stock.symbol) / 2 - 0.2);
    PRINTF("%s[label = \"%s: $%d\"];\n", ARROW, stock.symbol, stock.price);
}

void print_graphviz_footer() {
    PRINTF("}\n");
}

void print_graphviz(Stock stocks[MAX_SIZE]) {
    int i = 0;

    print_graphviz_header();

    for (; i < MAX_SIZE && stocks[i].symbol[0] != '\0'; i++) {
        print_graphviz_stock(stocks[i]);
    }

    print_graphviz_footer();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        PRINTF("Usage: %s <csv-file>\n", argv[0]);
        return 1;
    }

    Stock stocks[MAX_SIZE];

    if (!read_csv(argv[1], stocks)) {
        return 1;
    }

    print_graphviz(stocks);

    return 0;
}