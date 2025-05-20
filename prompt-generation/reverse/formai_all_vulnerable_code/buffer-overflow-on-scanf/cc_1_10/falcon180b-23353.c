//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_USER_LENGTH 50
#define TIME_LIMIT 60

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

struct user {
    char name[MAX_USER_LENGTH];
    int score;
    int accuracy;
};

void generate_random_word(struct word *word) {
    word->length = rand() % MAX_WORD_LENGTH + 1;
    for (int i = 0; i < word->length; i++) {
        word->word[i] = rand() % 26 + 'a';
    }
    word->word[word->length] = '\0';
}

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void test_user(struct word *word, struct user *user) {
    char input[MAX_WORD_LENGTH + 1];
    printf("Type the following word: %s\n", word->word);
    fflush(stdout);
    fgets(input, MAX_WORD_LENGTH + 1, stdin);
    input[strcspn(input, "\n")] = '\0';

    int correct = 0;
    for (int i = 0; i < word->length; i++) {
        if (input[i] == word->word[i]) {
            correct++;
        }
    }

    user->score += correct;
    user->accuracy = (float)correct / word->length * 100;
}

void print_results(struct user *user, int num_words) {
    printf("User: %s\n", user->name);
    printf("Score: %d\n", user->score);
    printf("Accuracy: %.2f%%\n", user->accuracy);
    printf("Words per minute: %.2f\n", (float)user->score / (5.0 * num_words));
}

int main() {
    srand(time(NULL));

    int num_words;
    printf("Enter the number of words to type (1-1000): ");
    scanf("%d", &num_words);

    struct word *words = malloc(sizeof(struct word) * num_words);
    for (int i = 0; i < num_words; i++) {
        generate_random_word(&words[i]);
    }

    qsort(words, num_words, sizeof(struct word), compare_strings);

    struct user user;
    printf("Enter your name: ");
    scanf("%s", user.name);

    int score = 0;
    int correct = 0;
    for (int i = 0; i < num_words; i++) {
        test_user(&words[i], &user);
        correct += user.accuracy * 5;
        score += 5;
    }

    print_results(&user, num_words);

    free(words);

    return 0;
}