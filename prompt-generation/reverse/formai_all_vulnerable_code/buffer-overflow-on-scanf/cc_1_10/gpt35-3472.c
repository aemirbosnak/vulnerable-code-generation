//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char input[1024]; // buffer for user input
    int wordsPerMinute = 0; // the user's measured typing speed (in words per minute)
    int errors = 0; // the number of errors made by the user
    int secondsElapsed = 0; // the number of seconds elapsed during the test
    time_t startTime, endTime; // to keep track of test timing
    srand(time(NULL)); // seed the random number generator
    
    printf("Welcome to the typing speed test!\n");
    printf("You will be given a set of random words to type as quickly and accurately as possible.\n");
    printf("Press any key to start the test.\n");
    getchar(); // wait for user input to start test
    
    // generate a random set of words for the user to type
    const char *wordList[] = {"cat", "dog", "squirrel", "bear", "lion", "tiger", "elephant", "rhinoceros", "hippopotamus", "crocodile",
                              "rat", "hamster", "rabbit", "ferret", "guinea pig", "parakeet", "canary", "goldfish", "lizard", "snake",
                              "pizza", "hamburger", "sushi", "spaghetti", "tacos", "burritos", "sandwich", "hot dog", "steak", "lobster",
                              "car", "truck", "bicycle", "motorcycle", "bus", "train", "airplane", "boat", "submarine", "space shuttle"};
    const int numWords = sizeof(wordList) / sizeof(wordList[0]);
    
    // the test will last 60 seconds
    startTime = time(NULL);
    endTime = time(NULL) + 60;
    
    while (time(NULL) < endTime) { // loop until 60 seconds elapse
        int randomIndex = rand() % numWords; // choose a random word from the list
        printf("%s ", wordList[randomIndex]); // print the word for the user to type
        fflush(stdout); // force the print to appear on the console
        scanf("%s", input); // read the user's input
        
        if (strcmp(input, wordList[randomIndex]) == 0) { // the input matches the word
            wordsPerMinute++;
        } else { // the input does not match the word
            errors++;
        }
        
        secondsElapsed = (int) difftime(time(NULL), startTime); // calculate how many seconds have passed
    }
    
    printf("\n\nTest complete!\n");
    printf("You typed an average of %d words per minute.\n", wordsPerMinute);
    printf("You made %d errors during the test.\n", errors);
    printf("You took %d seconds to complete the test.\n", secondsElapsed);
    
    return 0;
}