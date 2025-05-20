//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to shuffle letters in a given string
void shuffle(char* str) {
    int n = strlen(str);
    // iterate through the string from the end
    for(int i=n-1; i>0; i--) {
        // generate a random index
        int j = rand() % (i+1);
        // swap characters at i and j index
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    srand(time(NULL)); // seed for random number generation
    
    char* sentence = "The quick brown fox jumps over the lazy dog";
    printf("Type this sentence as fast as you can:\n%s\n", sentence);

    shuffle(sentence); // shuffle the sentence to make it harder to type

    time_t start_time = time(NULL); // start time
    char* user_input = malloc(strlen(sentence)+1); // allocate memory for user input
    scanf("%[^\n]s", user_input); // read user input until newline
    
    time_t end_time = time(NULL); // end time
    double time_taken = difftime(end_time, start_time); // calculate time taken

    // calculate accuracy and typing speed
    int correct_letters = 0;
    int total_letters = strlen(sentence);
    for(int i=0; i<total_letters; i++) {
        if(sentence[i] == user_input[i]) {
            correct_letters++;
        }
    }
    double accuracy = (double)correct_letters/total_letters;
    double typing_speed = (double)(total_letters/5)/(time_taken/60); // assuming an average word length of 5
    
    printf("Accuracy: %.2f %%\n", accuracy*100);
    printf("Typing Speed: %.2f wpm\n", typing_speed);

    free(user_input); // free allocated memory

    return 0;
}