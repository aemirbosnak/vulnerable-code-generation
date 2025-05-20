//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORDS_NUM 30
#define WORDS_LEN 10

char words[WORDS_NUM][WORDS_LEN] = {
    "future",
    "futuristic",
    "technology",
    "innovation",
    "automation",
    "robotics",
    "cybersecurity",
    "artificial",
    "intelligence",
    "nanotechnology",
    "quantum",
    "computing",
    "biotechnology",
    "augmented",
    "reality",
    "virtual",
    "reality",
    "machine",
    "learning",
    "blockchain",
    "cryptocurrency",
    "internet",
    "things",
    "smart",
    "cities",
    "cloud",
    "computing",
    "big",
    "data",
    "genomics",
    "neuroscience"
};

double testTypingSpeed(int duration_sec) {
    time_t start_time, end_time;
    int words_typed = 0;
    char typed_word[WORDS_LEN];
    double typing_speed;

    time(&start_time);
    while ((time(&end_time) - start_time) < duration_sec) {
        int word_index = rand() % WORDS_NUM;
        printf("[%d]: Type the word '%s': ", (words_typed + 1), words[word_index]);
        scanf("%s", typed_word);
        if (!strcmp(typed_word, words[word_index])) {
            printf("Correct!\n");
            words_typed++;
        } else {
            printf("Wrong! The correct word was '%s'\n", words[word_index]);
        }
    }
    typing_speed = ((double)words_typed / duration_sec) * 60;
    printf("Typing speed: %.1f words per minute\n", typing_speed);

    return typing_speed;
}

int main() {
    int duration_sec = 60;
    double typing_speed;

    srand(time(NULL));
    printf("Welcome to the Futuristic Typing Speed Test!\n");
    printf("You have %d seconds to type as many words as possible.\n", duration_sec);
    printf("Press Enter to start the test.\n");
    getchar();

    typing_speed = testTypingSpeed(duration_sec);

    if (typing_speed >= 60) {
        printf("Congratulations! You are a fast typist. You may have a future in typing jobs of the future!\n");
    } else {
        printf("Sorry, you need to improve your typing speed to compete in the future job market.\n");
    }

    return 0;
}