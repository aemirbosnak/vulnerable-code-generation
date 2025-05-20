//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_table(void);
void quiz(void);

int main(void)
{
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("1. Print the periodic table\n");
    printf("2. Take the quiz\n");
    printf("3. Exit\n");
    
    int option;
    scanf("%d", &option);
    
    switch(option)
    {
        case 1:
            print_table();
            break;
        case 2:
            quiz();
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid option\n");
            break;
    }
    
    return 0;
}

void print_table(void)
{
    printf("H   He\n");
    printf("Li  Be  B   C   N   O   F   Ne\n");
    printf("Na  Mg  Al  Si  P   S   Cl  Ar\n");
    printf("K   Ca  Sc  Ti  V   Cr  Mn  Fe  Co  Ni  Cu  Zn  Ga  Ge  As  Se  Br  Kr\n");
    printf("Rb  Sr  Y   Zr  Nb  Mo  Tc  Ru  Rh  Pd  Ag  Cd  In  Sn  Sb  Te  I   Xe\n");
    printf("Cs  Ba  La  Hf  Ta  W   Re  Os  Ir  Pt  Au  Hg  Tl  Pb  Bi  Po  At  Rn\n");
    printf("Fr  Ra  Ac  Rf  Db  Sg  Bh  Hs  Mt  Ds  Rg  Cn  Nh  Fl  Mc  Lv  Ts  Og\n");
}

void quiz(void)
{
    const int MAX_QUESTIONS = 10;
    const int NUM_ELEMENTS = 118;
    const int MAX_OPTIONS = 4;
    int questions = 0;
    int correct_answers = 0;
    
    srand(time(NULL));
    
    while (questions < MAX_QUESTIONS)
    {
        int element = rand() % NUM_ELEMENTS + 1;
        
        char* symbol;
        char name[50];
        
        switch(element)
        {
            case 1:
                symbol = "H";
                strcpy(name, "hydrogen");
                break;
            case 6:
                symbol = "C";
                strcpy(name, "carbon");
                break;
            case 8:
                symbol = "O";
                strcpy(name, "oxygen");
                break;
            case 16:
                symbol = "S";
                strcpy(name, "sulfur");
                break;
            case 26:
                symbol = "Fe";
                strcpy(name, "iron");
                break;
            case 47:
                symbol = "Ag";
                strcpy(name, "silver");
                break;
            case 53:
                symbol = "I";
                strcpy(name, "iodine");
                break;
            case 79:
                symbol = "Au";
                strcpy(name, "gold");
                break;
            default:
                continue;
                break;
        }
        
        int answer_index = rand() % MAX_OPTIONS;
        char* options[MAX_OPTIONS];
        
        options[answer_index] = symbol;
        
        for (int i = 0; i < MAX_OPTIONS; i++)
        {
            if (i == answer_index)
                continue;
                
            int incorrect_element = rand() % NUM_ELEMENTS + 1;
            char* incorrect_symbol;
            
            switch(incorrect_element)
            {
                case 1:
                    incorrect_symbol = "H";
                    break;
                case 6:
                    incorrect_symbol = "C";
                    break;
                case 8:
                    incorrect_symbol = "O";
                    break;
                case 16:
                    incorrect_symbol = "S";
                    break;
                case 26:
                    incorrect_symbol = "Fe";
                    break;
                case 47:
                    incorrect_symbol = "Ag";
                    break;
                case 53:
                    incorrect_symbol = "I";
                    break;
                case 79:
                    incorrect_symbol = "Au";
                    break;
                default:
                    incorrect_symbol = "Xx";
                    break;
            }
            
            options[i] = incorrect_symbol;
        }
        
        printf("\nWhat element has the symbol %s?\n", symbol);
        printf("A. %s\n", options[0]);
        printf("B. %s\n", options[1]);
        printf("C. %s\n", options[2]);
        printf("D. %s\n", options[3]);
        
        char player_choice;
        scanf(" %c", &player_choice);
        
        if (player_choice == 'A' && options[0] == symbol)
        {
            correct_answers++;
        }
        
        else if (player_choice == 'B' && options[1] == symbol)
        {
            correct_answers++;
        }
        
        else if (player_choice == 'C' && options[2] == symbol)
        {
            correct_answers++;
        }
        
        else if (player_choice == 'D' && options[3] == symbol)
        {
            correct_answers++;
        }
        
        else
        {
            printf("Wrong answer. The correct answer is %s.\n", symbol);
        }
        
        questions++;
    }
    
    printf("\nYour final score is %d out of %d.\n", correct_answers, MAX_QUESTIONS);
}