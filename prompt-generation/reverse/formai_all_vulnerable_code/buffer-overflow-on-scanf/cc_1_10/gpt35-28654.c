//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include<stdio.h>
#include<string.h>

int main(){
  char str[100], substring[20], replacement[20], new_str[100];
  int replace_count=0;

  //Prompting user to enter the string, substring and replacement
  printf("Enter the string: ");
  fgets(str, 100, stdin);
  printf("Enter the substring to replace: ");
  scanf("%s", substring);
  printf("Enter the replacement: ");
  scanf("%s", replacement);

  //Finding the length of the substring and the string
  int sub_len=strlen(substring), str_len=strlen(str);

  //Iterating through the string to find the substring and replace it
  for(int i=0, j=0;i<str_len;){
    int found=0;

    //Checking if the current index matches the first index of the substring
    if(str[i]==substring[j]){
      //Iterating through the substring to check if it completely matches the part of the string
      int k, l;
      for(k=i, l=0;l<sub_len;k++, l++){
        if(str[k]!=substring[l]){
          break;
        }
      }
      //If the substring was found, replacing it and counting the number of replacements made
      if(l==sub_len){
        replace_count++;
        strcat(new_str,replacement);
        i+=sub_len;
        j=0;
        found=1;
      }
    }
    //If the current index does not match the first index of the substring, adding the current character to the new string
    if(!found){
      strncat(new_str,&str[i],1);
      i++;
      j=0;
    }
  }
  //Displaying the original string and the new string with the number of replacements made
  printf("Original String: %s", str);
  printf("New String: %s\n", new_str);
  printf("Number of Substring Replacements Made: %d\n", replace_count);
  return 0;
}