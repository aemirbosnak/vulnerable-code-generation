//FormAI DATASET v1.0 Category: Computer Biology ; Style: excited
//Oh yeah, are you ready for some awesome computer biology program? Let's go!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining the structure for the DNA sequences
struct DNA
{
  char sequence[100]; //maximum of 100 nucleotide bases
  int length; //length of the sequence
};

//function to read the DNA sequence from the user and store in the structure
void read_DNA(struct DNA* dna)
{
  printf("Enter the DNA sequence: ");
  scanf("%s", dna->sequence); //reading the sequence from user
  dna->length = strlen(dna->sequence); //calculate the length and store in the structure
}

//function to print the DNA sequence stored in the structure
void print_DNA(struct DNA dna)
{
  printf("DNA sequence: %s\n", dna.sequence); //print the sequence
  printf("Sequence length: %d\n", dna.length); //print the length
}

//function to calculate the GC content of DNA sequence
float calculate_GC_content(struct DNA dna)
{
  int gc_count = 0; //initialize gc_count variable
  for(int i=0; i<dna.length; i++)
  {
    if(dna.sequence[i] == 'G' || dna.sequence[i] == 'C')
    {
      gc_count++; //increment gc_count if the base is G or C
    }
  }
  float gc_content = ((float)gc_count/dna.length)*100; //calculate the GC content
  return gc_content;
}

//main function
int main()
{
  printf("Welcome to the DNA analysis program!\n");
  printf("Please enter the DNA sequence you want to analyze:\n");

  //create a DNA structure and then read and store the DNA sequence entered by the user
  struct DNA myDNA;
  read_DNA(&myDNA);

  //print the DNA sequence and its length
  printf("\n");
  print_DNA(myDNA);

  //calculate and print the GC content of the DNA sequence
  float gc_content = calculate_GC_content(myDNA);
  printf("GC content of the DNA sequence: %.2f%%\n", gc_content);

  return 0; //program execution ends here
}
//That was easy and fun! Do you want to explore more? I got other exciting programs waiting for you.