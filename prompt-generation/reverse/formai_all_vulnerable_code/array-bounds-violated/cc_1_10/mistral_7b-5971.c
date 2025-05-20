//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

typedef struct {
    int color_code;
    char *message;
} Message;

Message mood_ring[6] = {
    {31, "You seem grumpy today!"},
    {32, "You look as happy as a clam!"},
    {33, "You're radiating positivity!"},
    {34, "You're feeling a bit blue..."},
    {35, "You're as radiant as a rose!"},
    {36, "You're in a thoughtful mood..."}
};

int get_random_number(int min, int max) {
    int random;
    random = rand() % (max - min + 1) + min;
    return random;
}

int main() {
    int happiness_level;
    int mood_ring_color;

    srand(time(NULL));

    happiness_level = get_random_number(1, 10);
    mood_ring_color = get_random_number(1, 6);

    printf("%s%s%s\n", COLOR_RESET, "Once upon a time, there was a magical Mood Ring...", COLOR_RESET);
    printf("%s%s\n", COLOR_RESET, "----------------------------------------------------");
    printf("%s%s%s\n", COLOR_RESET, "Today, as you wear it, it reveals your happiness level...", COLOR_RESET);
    printf("%s%d%s\n", COLOR_RESET, happiness_level, COLOR_RESET);
    printf("%s%s%s\n", COLOR_RESET, "And, as a surprise, the Mood Ring also shares a cheerful message...", COLOR_RESET);
    printf("%s%s%s\n", COLOR_RESET, "----------------------------------------------------", COLOR_RESET);
    printf("%s%s\n", COLOR_MAGENTA, mood_ring[mood_ring_color].message);
    printf("%s%s\n", COLOR_RESET, "Have a cheerful day!");

    return 0;
}