//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>

//function to shuffle the array
void shuffleArray(int arr[],int n){
  int i,temp;
  srand(time(NULL)); //initialize random seed
  for(i=n-1;i>0;i--){
    int j=rand()%(i+1); //get random index
    //swap the elements of array at index i and j
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
  }
}

int main(){
  int elements[118]={1,3,4,5,6,7,8,9,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,
                    28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,
                    51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,
                    75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,
                    99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118};
  char symbol[118][3]={"H ","Li","Be","B ","C ","N ","O ","F ","Na","Mg","Al","Si","P ","S ","Cl","Ar",
                    "K ","Ca","Sc","Ti","V ","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
                    "Rb","Sr","Y ","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I ","Xe",
                    "Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta",
                    "W ","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa",
                    "U ","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn",
                    "Nh","Fl","Mc","Lv","Ts","Og"};

  int numQuestions,option,answer,numCorrect=0;
  printf("Welcome to the Periodic Table Quiz!\n");
  printf("How many questions would you like to answer (maximum 118)? ");
  scanf("%d",&numQuestions);

  //shuffle the array of elements to get random questions
  shuffleArray(elements,118);

  //loop through the number of questions asked by the user
  for(int i=0;i<numQuestions;i++){
    printf("\nQuestion %d:\n",i+1);
    printf("Which element has the symbol %s?\n",symbol[elements[i]-1]);
    printf("Enter the atomic number of the element: ");
    scanf("%d",&answer);
    if(answer==elements[i]){
      printf("Correct!\n");
      numCorrect++;
    }
    else{
      printf("Incorrect! The correct answer is %d\n",elements[i]);
    }

    //ask the user if they want to continue with the quiz
    if(i<numQuestions-1){  //do not prompt for last question
      printf("\nDo you want to continue with the quiz? (1=yes, 0=no) ");
      scanf("%d",&option);
      if(!option){
        break;
      }
    }
  }

  //display the user's score
  printf("\nQuiz completed! You answered %d out of %d questions correctly.\n",numCorrect,numQuestions);
  
  return 0;
}