//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h> //for random number generation

//Function to print the periodic table
void print_periodic_table(){
    printf("\nH  He Li Be  B  C  N  O  F Ne\n");
    printf("Na Mg Al Si P  S  Cl Ar\n");
    printf("K  Ca Sc Ti V  Cr Mn Fe Co Ni Cu Zn\n");
    printf("Ga Ge As Se Br Kr\n");
    printf("Rb Sr Y  Zr Nb Mo Tc Ru Rh Pd Ag Cd\n");
    printf("In Sn Sb Te I  Xe\n");
    printf("Cs Ba La Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu\n");
    printf("Tl Pb Bi Po At Rn\n");
    printf("Fr Ra Ac Th Pa U  Np Pu Am Cm Bk Cf Es Fm Md No Lr\n");
}

int main(){
    //Initializing variables
    int score = 0;
    time_t t;
    srand((unsigned) time(&t)); //Seeding rand function to generate random numbers
    int atomic_numbers[] = {1, 3, 5, 7, 12, 19, 25, 35, 47, 56, 74, 80, 83, 92};
    int random_number, random_question;
    char user_answer;

    //Printing the periodic table
    printf("Here's the periodic table. Use it to answer the questions below.\n");
    print_periodic_table();

    //Playing game
    for(int i=1; i<=5; i++){
        //Generating random atomic number
        random_number = atomic_numbers[rand() % 14];
        //Asking random question based on atomic number
        printf("\nQuestion %d. What is the symbol of the element with atomic number %d?\n", i, random_number);
        printf("a) ");
        switch(random_number){
            case 1:
                printf("H");
                break;
            case 3:
                printf("Li");
                break;
            case 5:
                printf("B");
                break;
            case 7:
                printf("N");
                break;
            case 12:
                printf("Mg");
                break;
            case 19:
                printf("K");
                break;
            case 25:
                printf("Mn");
                break;
            case 35:
                printf("Br");
                break;
            case 47:
                printf("Ag");
                break;
            case 56:
                printf("Ba");
                break;
            case 74:
                printf("W");
                break;
            case 80:
                printf("Hg");
                break;
            case 83:
                printf("Bi");
                break;
            case 92:
                printf("U");
                break;
        }
        printf("\nb) ");
        switch(random_number){
            case 1:
                printf("He");
                break;
            case 3:
                printf("Be");
                break;
            case 5:
                printf("C");
                break;
            case 7:
                printf("O");
                break;
            case 12:
                printf("Al");
                break;
            case 19:
                printf("Ca");
                break;
            case 25:
                printf("Fe");
                break;
            case 35:
                printf("Cl");
                break;
            case 47:
                printf("Cu");
                break;
            case 56:
                printf("Sr");
                break;
            case 74:
                printf("Pt");
                break;
            case 80:
                printf("Pb");
                break;
            case 83:
                printf("P");
                break;
            case 92:
                printf("Pu");
                break;
        }
        printf("\nc) ");
        switch(random_number){
            case 1:
                printf("Na");
                break;
            case 3:
                printf("B");
                break;
            case 5:
                printf("N");
                break;
            case 7:
                printf("F");
                break;
            case 12:
                printf("Mn");
                break;
            case 19:
                printf("Ni");
                break;
            case 25:
                printf("Cu");
                break;
            case 35:
                printf("I");
                break;
            case 47:
                printf("Au");
                break;
            case 56:
                printf("Ba");
                break;
            case 74:
                printf("Au");
                break;
            case 80:
                printf("Zn");
                break;
            case 83:
                printf("Po");
                break;
            case 92:
                printf("Np");
                break;
        }
        printf("\nd) ");
        switch(random_number){
            case 1:
                printf("Li");
                break;
            case 3:
                printf("Na");
                break;
            case 5:
                printf("O");
                break;
            case 7:
                printf("Ne");
                break;
            case 12:
                printf("Mg");
                break;
            case 19:
                printf("Fe");
                break;
            case 25:
                printf("Zn");
                break;
            case 35:
                printf("S");
                break;
            case 47:
                printf("Zn");
                break;
            case 56:
                printf("Ra");
                break;
            case 74:
                printf("Ir");
                break;
            case 80:
                printf("Fe");
                break;
            case 83:
                printf("Te");
                break;
            case 92:
                printf("Th");
                break;
        }
        printf("\n");

        //Getting user's answer
        printf("Enter your answer (a, b, c, or d): ");
        scanf(" %c", &user_answer);

        //Checking user's answer
        random_question = rand() % 4; //Generating random number for which option is correct
        switch(random_question){
            case 0:
                if(user_answer == 'a'){
                    printf("Correct!\n");
                    score++;
                }
                else{
                    printf("Incorrect. The correct answer is a)\n");
                }
                break;
            case 1:
                if(user_answer == 'b'){
                    printf("Correct!\n");
                    score++;
                }
                else{
                    printf("Incorrect. The correct answer is b)\n");
                }
                break;
            case 2:
                if(user_answer == 'c'){
                    printf("Correct!\n");
                    score++;
                }
                else{
                    printf("Incorrect. The correct answer is c)\n");
                }
                break;
            case 3:
                if(user_answer == 'd'){
                    printf("Correct!\n");
                    score++;
                }
                else{
                    printf("Incorrect. The correct answer is d)\n");
                }
                break;
        }
    }

    //Printing final score
    printf("\nYour final score is %d out of 5.\n", score);
    if(score == 5){
        printf("Congratulations! You got a perfect score!\n");
    }
    else if(score >= 3){
        printf("Good job!\n");
    }
    else{
        printf("Better luck next time!\n");
    }

    return 0;
}