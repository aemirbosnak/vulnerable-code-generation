//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_WORD_LENGTH 100
#define MAX_TRANSLATIONS 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char catLanguage[MAX_WORD_LENGTH];
} Translation;

Translation translations[MAX_TRANSLATIONS];
int translationCount = 0;
sem_t sem;

void* addTranslation(void* arg) {
    char english[MAX_WORD_LENGTH];
    char catLanguage[MAX_WORD_LENGTH];

    printf("Enter English word: ");
    fgets(english, sizeof(english), stdin);
    english[strcspn(english, "\n")] = 0; // Remove newline

    printf("Enter Cat Language equivalent: ");
    fgets(catLanguage, sizeof(catLanguage), stdin);
    catLanguage[strcspn(catLanguage, "\n")] = 0; // Remove newline

    sem_wait(&sem);
    strcpy(translations[translationCount].english, english);
    strcpy(translations[translationCount].catLanguage, catLanguage);
    translationCount++;
    sem_post(&sem);

    printf("Translation added!\n");
    return NULL;
}

void* translateWord(void* arg) {
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to translate: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = 0; // Remove newline

    sem_wait(&sem);
    for (int i = 0; i < translationCount; i++) {
        if (strcmp(word, translations[i].english) == 0) {
            printf("Translation: %s\n", translations[i].catLanguage);
            sem_post(&sem);
            return NULL;
        }
    }
    sem_post(&sem);
    printf("Translation not found!\n");
    return NULL;
}

void* displayTranslations(void* arg) {
    sem_wait(&sem);
    printf("\nCurrent Translations:\n");
    for (int i = 0; i < translationCount; i++) {
        printf("English: %s - Cat Language: %s\n", translations[i].english, translations[i].catLanguage);
    }
    sem_post(&sem);
    return NULL;
}

int main() {
    pthread_t threads[3];
    sem_init(&sem, 0, 1);
    int choice;

    while (1) {
        printf("\n=== C Cat Language Translator ===\n");
        printf("1. Add Translation\n");
        printf("2. Translate Word\n");
        printf("3. Display All Translations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left in buffer

        switch (choice) {
            case 1:
                pthread_create(&threads[0], NULL, addTranslation, NULL);
                pthread_join(threads[0], NULL);
                break;
            case 2:
                pthread_create(&threads[1], NULL, translateWord, NULL);
                pthread_join(threads[1], NULL);
                break;
            case 3:
                pthread_create(&threads[2], NULL, displayTranslations, NULL);
                pthread_join(threads[2], NULL);
                break;
            case 4:
                sem_destroy(&sem);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}