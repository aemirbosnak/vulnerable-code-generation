//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char elem[] = {'H','He','Li','Be','B','C','N','O','F','Ne','Na',
                    'Mg','Al','Si','P','S','Cl','Ar','K','Ca',
                    'Sc','Ti','V','Cr','Mn','Fe','Co','Ni','Cu','Zn',
                    'Ga','Ge','As', 'Se','Br', 'Kr','Rb','Sr','Y','Zr',
                    'Nb','Mo','Tc','Ru','Rh','Pd','Ag','Cd','In','Sn',
                    'Sb','Te','I', 'Xe','Cs','Ba','La','Ce','Pr','Nd',
                    'Pm','Sm','Eu','Gd','Tb','Dy','Ho','Er','Tm','Yb',
                    'Lu','Hf','Ta','W','Re','Os','Ir','Pt','Au','Hg',
                    'Tl','Pb','Bi','Th','Pa','U','Np','Pu','Am','Cm',
                    'Bk','Cf','Es','Fm','Md','No','Lr','Rf','Db','Sg',
                    'Bh','Hs','Mt','Ds','Rg','Cn','Nh','Fl','Mc','Lv'};
    float mass[] = {1.0079, 4.0026, 6.941, 9.0122, 10.81, 12.01, 14.01, 16.00, 19.00, 20.18, 22.99, 24.31, 26.98, 28.09, 30.97, 32.07, 35.45, 39.95, 39.10, 40.08, 44.96, 47.87, 50.94, 52.00, 54.94, 55.85, 58.93, 58.69, 63.55, 65.38, 69.72, 72.63, 74.92, 78.96, 79.90, 83.80, 85.47, 87.62, 88.91, 91.22, 92.91, 95.94, 98.00, 101.07, 102.91, 106.42, 107.87, 112.41, 114.82, 118.71, 121.76, 127.60, 126.90, 131.29, 132.91, 137.33, 138.91, 140.12, 140.91, 144.24, 145.00, 150.36, 151.96, 157.25, 158.90, 162.50, 164.93, 167.26, 168.93, 173.04, 174.97, 178.49, 180.95, 183.84, 186.21, 190.23, 192.22, 195.08, 196.97, 200.59, 204.38, 207.2, 208.98, 209.0, 210.0, 222.0, 223.0, 226.0, 227.0, 231.04, 232.04, 237.05, 238.03, 243.06, 244.06, 247.07, 247.07, 251.08, 252.08, 257.10, 258.10};
    
    printf("Welcome to the C Periodic Table Quiz! \n");
    printf("We will test your knowledge on the periodic table of elements. \n");
    printf("Are you ready to begin? \nPress 1 to start or any other key to exit. \n");
    
    int start;
    scanf("%d", &start);

    if(start==1)
    {
        printf("Great! Let's begin... \n Note: Please use only uppercase letters for answer. \n\n");

        int score = 0;
        int total = 20;

        for (int i = 0; i < total; i++)
        {
            int index = rand() % 118; //Generate random index
            printf("\n%d. What is the symbol for element with atomic mass %0.2f? ", i+1, mass[index]);
            char ans[3];
            scanf("%s", ans);

            if (ans[0] == elem[index])
            {
                printf("Correct! \n");
                score++;
            }
            else
            {
                printf("Incorrect. The correct answer is '%c'. \n", elem[index]);
            }
        }

        float percentage = ((float)score/total)*100;

        printf("\nCongratulations! You have completed the quiz. \n");
        printf("You scored %d out of %d which is %0.2f%%.\n", score, total, percentage);
    }
    else
    {
        printf("Goodbye! \n");
    }

    return 0;
}