//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

  char catlanguage[100];
  int i,j=0;
  printf("Enter your sentence in Cat Language: ");
  gets(catlanguage);

  //Reversing the letters of the words
  for(i=0;i<strlen(catlanguage);i++){
    if(catlanguage[i]==' ' || i==strlen(catlanguage)-1){
      //reversing each word
      if(i==strlen(catlanguage)-1){
        catlanguage[i+1]='\0';
      }
      int start=j,end=i-1;
      while(start<end){
        char temp=catlanguage[start];
        catlanguage[start]=catlanguage[end];
        catlanguage[end]=temp;
        start++;
        end--;
      }
      j=i+1;
    }
  }

  //replacing meow with "I"
  for(i=0;i<strlen(catlanguage);i++){
    if(catlanguage[i]=='m'&& catlanguage[i+1]=='e'&& catlanguage[i+2]=='o'&& catlanguage[i+3]=='w'){
      catlanguage[i]='I';
      for(j=i+1;j<=strlen(catlanguage)-4;j++){
        catlanguage[j]=catlanguage[j+3];
      }
      catlanguage[j]='\0';
    }
  }

  //replacing purr with "the"
  for(i=0;i<strlen(catlanguage);i++){
    if(catlanguage[i]=='p'&& catlanguage[i+1]=='u'&& catlanguage[i+2]=='r'&& catlanguage[i+3]=='r'){
      catlanguage[i+2]='e';
      catlanguage[i+3]='\0';
      for(j=i+1;j<=strlen(catlanguage)-4;j++){
        catlanguage[j]=catlanguage[j+3];
      }
      catlanguage[j]='\0';
    }
  }

  printf("Translated Sentence: %s\n",catlanguage);

  return 0;
}