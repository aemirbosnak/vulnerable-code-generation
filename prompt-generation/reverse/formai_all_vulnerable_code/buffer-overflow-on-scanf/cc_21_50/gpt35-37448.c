//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int getQuestionAnswer(int qNum);
int testAnswer(int answer, int correct_answer);

int main()
{
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Can you name the atomic symbol each element represents?\n");
    
    srand(time(NULL)); // Seed the random number generator
    
    int score = 0;
    int correct_answer;
    int answer;
    
    for(int i = 1; i <= 10; i++) // Ask 10 questions
    {
        int question_num = rand() % 118 + 1; // Generate a random question number
        
        correct_answer = getQuestionAnswer(question_num);
        
        printf("\nQuestion %d: What is the atomic symbol for element number %d?\n", i, question_num);
        scanf("%s", &answer);
        
        if(testAnswer(answer, correct_answer))
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is: %s\n", correct_answer);
        }
    }
    
    printf("\nQuiz complete! You scored %d out of 10.\n", score);
    
    return 0;
}

int getQuestionAnswer(int qNum)
{
    switch(qNum)
    {
        case 1:
            return "H";
            break;
        case 2:
            return "He";
            break;
        case 3:
            return "Li";
            break;
        case 4:
            return "Be";
            break;
        case 5:
            return "B";
            break;
        case 6:
            return "C";
            break;
        case 7:
            return "N";
            break;
        case 8:
            return "O";
            break;
        case 9:
            return "F";
            break;
        case 10:
            return "Ne";
            break;
        case 11:
            return "Na";
            break;
        case 12:
            return "Mg";
            break;
        case 13:
            return "Al";
            break;
        case 14:
            return "Si";
            break;
        case 15:
            return "P";
            break;
        case 16:
            return "S";
            break;
        case 17:
            return "Cl";
            break;
        case 18:
            return "Ar";
            break;
        case 19:
            return "K";
            break;
        case 20:
            return "Ca";
            break;
        case 21:
            return "Sc";
            break;
        case 22:
            return "Ti";
            break;
        case 23:
            return "V";
            break;
        case 24:
            return "Cr";
            break;
        case 25:
            return "Mn";
            break;
        case 26:
            return "Fe";
            break;
        case 27:
            return "Co";
            break;
        case 28:
            return "Ni";
            break;
        case 29:
            return "Cu";
            break;
        case 30:
            return "Zn";
            break;
        case 31:
            return "Ga";
            break;
        case 32:
            return "Ge";
            break;
        case 33:
            return "As";
            break;
        case 34:
            return "Se";
            break;
        case 35:
            return "Br";
            break;
        case 36:
            return "Kr";
            break;
        case 37:
            return "Rb";
            break;
        case 38:
            return "Sr";
            break;
        case 39:
            return "Y";
            break;
        case 40:
            return "Zr";
            break;
        case 41:
            return "Nb";
            break;
        case 42:
            return "Mo";
            break;
        case 43:
            return "Tc";
            break;
        case 44:
            return "Ru";
            break;
        case 45:
            return "Rh";
            break;
        case 46:
            return "Pd";
            break;
        case 47:
            return "Ag";
            break;
        case 48:
            return "Cd";
            break;
        case 49:
            return "In";
            break;
        case 50:
            return "Sn";
            break;
        case 51:
            return "Sb";
            break;
        case 52:
            return "Te";
            break;
        case 53:
            return "I";
            break;
        case 54:
            return "Xe";
            break;
        case 55:
            return "Cs";
            break;
        case 56:
            return "Ba";
            break;
        case 57:
            return "La";
            break;
        case 58:
            return "Ce";
            break;
        case 59:
            return "Pr";
            break;
        case 60:
            return "Nd";
            break;
        case 61:
            return "Pm";
            break;
        case 62:
            return "Sm";
            break;
        case 63:
            return "Eu";
            break;
        case 64:
            return "Gd";
            break;
        case 65:
            return "Tb";
            break;
        case 66:
            return "Dy";
            break;
        case 67:
            return "Ho";
            break;
        case 68:
            return "Er";
            break;
        case 69:
            return "Tm";
            break;
        case 70:
            return "Yb";
            break;
        case 71:
            return "Lu";
            break;
        case 72:
            return "Hf";
            break;
        case 73:
            return "Ta";
            break;
        case 74:
            return "W";
            break;
        case 75:
            return "Re";
            break;
        case 76:
            return "Os";
            break;
        case 77:
            return "Ir";
            break;
        case 78:
            return "Pt";
            break;
        case 79:
            return "Au";
            break;
        case 80:
            return "Hg";
            break;
        case 81:
            return "Tl";
            break;
        case 82:
            return "Pb";
            break;
        case 83:
            return "Bi";
            break;
        case 84:
            return "Po";
            break;
        case 85:
            return "At";
            break;
        case 86:
            return "Rn";
            break;
        case 87:
            return "Fr";
            break;
        case 88:
            return "Ra";
            break;
        case 89:
            return "Ac";
            break;
        case 90:
            return "Th";
            break;
        case 91:
            return "Pa";
            break;
        case 92:
            return "U";
            break;
        case 93:
            return "Np";
            break;
        case 94:
            return "Pu";
            break;
        case 95:
            return "Am";
            break;
        case 96:
            return "Cm";
            break;
        case 97:
            return "Bk";
            break;
        case 98:
            return "Cf";
            break;
        case 99:
            return "Es";
            break;
        case 100:
            return "Fm";
            break;
        case 101:
            return "Md";
            break;
        case 102:
            return "No";
            break;
        case 103:
            return "Lr";
            break;
        case 104:
            return "Rf";
            break;
        case 105:
            return "Db";
            break;
        case 106:
            return "Sg";
            break;
        case 107:
            return "Bh";
            break;
        case 108:
            return "Hs";
            break;
        case 109:
            return "Mt";
            break;
        case 110:
            return "Ds";
            break;
        case 111:
            return "Rg";
            break;
        case 112:
            return "Cn";
            break;
        case 113:
            return "Nh";
            break;
        case 114:
            return "Fl";
            break;
        case 115:
            return "Mc";
            break;
        case 116:
            return "Lv";
            break;
        case 117:
            return "Ts";
            break;
        case 118:
            return "Og";
            break;
    }
}

int testAnswer(int answer, int correct_answer)
{
    if(!strcasecmp(answer, correct_answer))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}