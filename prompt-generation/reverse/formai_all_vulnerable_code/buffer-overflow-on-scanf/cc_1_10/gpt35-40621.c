//FormAI DATASET v1.0 Category: Spell checking ; Style: happy
#include<stdio.h>
#include<string.h>

char* happyMessage1 = "Oh happy day, my friend! It's spell-checking time! :)";
char* happyMessage2 = "You're doing great! Keep going! :D";
char* happyMessage3 = "Awesome job! You're a spell-checking PRO now! :)";
char* happyMessage4 = "High-five! :D";
char* happyMessage5 = "You're making spell-checking look easy!";

char* errorMessage1 = "Oops, that word was not found in the dictionary. :( ";
char* errorMessage2 = "Uh-oh, that word is spelled incorrectly. :( ";
char* errorMessage3 = "Looks like you made a typo. Try again! :( ";
char* errorMessage4 = "That's not a word. Please try again. :( ";
char* errorMessage5 = "Oh no, that word is not in the dictionary. :( ";

char* dictionary[] = {"happy", "day", "spell-checking", "time", "friend", "great", "awesome", "job", "high-five", "easy", "dictionary", "typo"};

int main()
{
    printf("%s\n\n", happyMessage1);
    
    while(1)
    {
        char input[50];
        printf("What word do you want to check? (Enter 'exit' to quit)\n");
        scanf("%s", input);
        
        if(strcmp(input, "exit") == 0)
        {
            break;
        }
        
        int found = 0;
        for(int i=0; i<12; i++)
        {
            if(strcmp(input, dictionary[i]) == 0)
            {
                found = 1;
                break;
            }
        }
        
        if(found == 1)
        {
            printf("%s\n\n", happyMessage2);
        }
        else
        {
            printf("%s\n\n", errorMessage1);
        }
    }
    
    printf("%s\n", happyMessage3);
    printf("%s\n", happyMessage4);
    printf("%s\n", happyMessage5);
    
    return 0;
}