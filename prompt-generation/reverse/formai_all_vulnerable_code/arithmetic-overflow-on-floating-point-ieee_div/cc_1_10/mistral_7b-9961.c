//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>

#define MAX_LINE_LEN 1024
#define TICKER_FILE "/var/run/ticker.txt"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define RESET "\033[0m"

struct ticker {
    char symbol[5];
    float last_price;
    float change;
    float change_percent;
};

void get_ticker_data(struct ticker *ticker, char *line) {
    sscanf(line, "%s%f%f%f", ticker->symbol, &ticker->last_price, &ticker->change);
    ticker->change_percent = ticker->change / ticker->last_price * 100;
}

void clear_screen() {
    printf("%c[2J", 27);
}

void print_ticker_header() {
    printf(BOLD "%-5s %-10s %-10s %-10s %s\n", "Symbol", "Last Price", "Change", "% Change", RESET);
}

void print_ticker(struct ticker ticker) {
    printf(BOLD "%-5s $%-9.2f $%-9.6s %-9.3f%%\n", ticker.symbol, ticker.last_price, ticker.change > 0 ? "+" : "", ticker.change, ticker.change_percent > 0 ? "+" : "");
}

void read_ticker_file() {
    int fd;
    char line[MAX_LINE_LEN];
    struct ticker tickers[10];
    int num_tickers = 0;

    fd = open(TICKER_FILE, O_RDONLY);

    if (fd < 0) {
        perror("Error opening ticker file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LEN, fd) != NULL) {
        if (num_tickers >= 10) {
            printf(RED "Error: Too many tickers in file\n");
            exit(EXIT_FAILURE);
        }

        get_ticker_data(&tickers[num_tickers], line);
        num_tickers++;
    }

    close(fd);

    for (int i = 0; i < num_tickers; i++) {
        print_ticker(tickers[i]);
    }
}

void setup_terminal() {
    struct termios old, new;

    tcgetattr(STDIN_FILENO, &old);
    new = old;

    new.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &new);
}

int main() {
    clear_screen();
    print_ticker_header();

    setup_terminal();

    read_ticker_file();

    printf(RED "\nPress any key to exit...\n");
    getchar();

    printf(BOLD "\nShocked Stock Market Tracker v1.0\n" RESET);

    return 0;
}