//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

// Colors for terminal output
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"

// RAM usage monitoring function
int get_ram_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

// ASCII art of a RAM chip
void print_ram_chip() {
    printf(
        "                .-~~-._             .-~~-._                \n"
        "              ,'       `.           ,'       `.              \n"
        "            ,'           `.       ,'           `.            \n"
        "          ,'               `.   ,'               `.          \n"
        "        ,'                   `. ,'                   `.        \n"
        "      ,'                       |                       `.      \n"
        "    ,'                         |                         `.    \n"
        "  ,'                           |                           `.  \n"
        "  |                           ,'                           |  \n"
        "  |                           |                           |  \n"
        "  |                           |                           |  \n"
        "  |                           |                           |  \n"
        "  |                           |                           |  \n"
        "  |                           |                           |  \n"
        "  `.                         |                         ,'  \n"
        "    `.                       |                       ,'    \n"
        "      `.                     |                     ,'      \n"
        "        `.                   |                   ,'        \n"
        "          `.                 |                 ,'          \n"
        "            `.               |               ,'            \n"
        "              `.             |             ,'              \n"
        "                `-.._____..-'`-.._____..-'                \n"
    );
}

int main() {
    // Initialize some variables
    int max_ram_usage = get_ram_usage();
    int current_ram_usage = get_ram_usage();
    int previous_ram_usage = 0;
    int ram_usage_difference = current_ram_usage - previous_ram_usage;
    int i = 0;

    // Loop forever (or until the user quits)
    while (1) {
        // Get the current RAM usage
        current_ram_usage = get_ram_usage();

        // Calculate the RAM usage difference
        ram_usage_difference = current_ram_usage - previous_ram_usage;

        // Print the RAM usage information
        printf("%s", RESET);
        printf("Current RAM usage: %d MB\n", current_ram_usage);
        printf("Maximum RAM usage: %d MB\n", max_ram_usage);
        printf("RAM usage difference: %d MB\n", ram_usage_difference);

        // Print a funny message
        switch (i) {
            case 0:
                printf(YELLOW "Your RAM is like a hamster on a wheel, it just keeps running and running...\n" RESET);
                break;
            case 1:
                printf(GREEN "Your RAM is like a party animal, it never sleeps!\n" RESET);
                break;
            case 2:
                printf(BLUE "Your RAM is like a library, it's full of books but no one ever reads them...\n" RESET);
                break;
            case 3:
                printf(MAGENTA "Your RAM is like a dog, it's always hungry for more!\n" RESET);
                break;
            case 4:
                printf(CYAN "Your RAM is like a unicorn, it's magical and everyone wants one!\n" RESET);
                break;
            case 5:
                printf(WHITE "Your RAM is like a politician, it promises a lot but delivers very little...\n" RESET);
                break;
        }

        // Increment the counter
        i++;

        // Sleep for a bit
        sleep(1);

        // Update the previous RAM usage
        previous_ram_usage = current_ram_usage;
    }

    return 0;
}