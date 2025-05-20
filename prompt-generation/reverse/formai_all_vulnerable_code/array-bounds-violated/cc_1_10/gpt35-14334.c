//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: mind-bending
#include<stdio.h>
#include<ctype.h>
#include<string.h>

const char* CAT_WORDS[64] = {"meow", "purr", "hiss", "scratch", "claw", 
                             "whisker", "nip", "treats", "kitten", "litter box",
                             "milk", "mouse", "yarn", "nap", "paws", "collar",
                             "leash", "petting", "toy", "laser", "chase", "jump",
                             "hunt", "play", "sleep", "furry", "soft", "cuddle",
                             "knead", "lick", "groom", "shed", "hairball", "scratch post",
                             "tail", "ears", "eyes", "nose", "teeth", "whiskers",
                             "meat", "fish", "tuna", "chicken", "ham", "sausage",
                             "cheese", "mice cream", "treats", "crunch", "chomp", "yum",
                             "no", "yes", "love", "hate", "hungry", "thirsty"};

const char* ENGLISH_WORDS[64] = {"Hello", "How are you?", "What's up?", "Goodbye", "Thank you",
                                  "Meow", "Purr", "Hiss", "Scratch", "Claw",
                                  "Whisker", "Nip", "Treats", "Kitten", "Litter box", 
                                  "Milk", "Mouse", "Yarn", "Nap", "Paws", "Collar",
                                  "Leash", "Petting", "Toy", "Laser", "Chase", "Jump",
                                  "Hunt", "Play", "Sleep", "Furry", "Soft", "Cuddle",
                                  "Knead", "Lick", "Groom", "Shed", "Hairball", "Scratch post",
                                  "Tail", "Ears", "Eyes", "Nose", "Teeth", "Whiskers",
                                  "Meat", "Fish", "Tuna", "Chicken", "Ham", "Sausage",
                                  "Cheese", "Ice cream", "Treats", "Crunch", "Chomp", "Yum",
                                  "No", "Yes", "Love", "Hate", "Hungry", "Thirsty"};

int main()
{
    char cat_sentence[1024], cat_word[32], english_sentence[1024], english_word[32];
    int i, j, k;
    
    printf("Welcome to the C-Cat language translator!\n");
    printf("Enter a sentence in C-Cat language:\n");
    fgets(cat_sentence, 1024, stdin);
    cat_sentence[strlen(cat_sentence)-1] = '\0'; // Remove the newline character
    
    i = 0;
    j = 0;
    while(cat_sentence[i] != '\0')
    {
        k = 0;
        while(isalpha(cat_sentence[i]) || isdigit(cat_sentence[i]))
        {
            cat_word[k++] = cat_sentence[i++];
        }
        cat_word[k] = '\0';
        
        // Search for the C-Cat word in the list and replace it with the corresponding English word
        for(k = 0; k < 64; k++)
        {
            if(strcmp(cat_word, CAT_WORDS[k]) == 0)
            {
                strcpy(english_word, ENGLISH_WORDS[k]);
                strcat(english_sentence, english_word);
                j += strlen(english_word);
                break;
            }
        }
        
        // Add any other non-letter/non-digit characters as is
        if(!isalpha(cat_sentence[i]) && !isdigit(cat_sentence[i]))
        {
            english_sentence[j++] = cat_sentence[i++];
        }
    }
    
    english_sentence[j] = '\0';
    
    printf("\nThe corresponding sentence in English is:\n%s\n", english_sentence);
    
    return 0;
}