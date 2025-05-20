//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
   char name[50];
   char email[50];
   char phone[20];
   char education[100];
   char skills[100];
   char experience[100];
};

int main() {
   int i, j, k, n;
   struct Resume res[10];
   char edu_str[6][20] = { "BE", "BTech", "ME", "MTech", "MBA", "MCA" };
   char skill_str[5][20] = { "java", "C", "Python", "Ruby", "Swift" };

   // input section
   printf("Enter number of resumes you want to parse: ");
   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      printf("Enter name, email, phone, education, skills and experience of resume #%d:\n", i+1);
      scanf("%s %s %s %[^\n]%*c %[^\n]%*c %[^\n]%*c", res[i].name, res[i].email, res[i].phone, res[i].education, res[i].skills, res[i].experience);


      // check for parsing errors
      if (strlen(res[i].name) == 0 || strlen(res[i].email) == 0 || strlen(res[i].phone) == 0 ) {
         printf("Error: Name, email and phone are required.\n");
         return 1;
      }

   }

   // output section
   printf("\nResume Parsing Result:\n");
   printf("--------------------------\n");
   for (i = 0; i < n; i++) {
      printf("Resume #%d:\n", i+1);
      printf("Name: %s\n", res[i].name);
      printf("Email: %s\n", res[i].email);
      printf("Phone: %s\n", res[i].phone);
      printf("Education: %s\n", res[i].education);
      printf("Skills: ");
      for (j = 0; res[i].skills[j]; j++) {
         if (res[i].skills[j] == ',') res[i].skills[j] = ' ';
      }
      for (j = 0; j < 5; j++) {
         if (strstr(res[i].skills, skill_str[j])) {
            printf("%s, ", skill_str[j]);
         }
      }
      printf("\nExperience: %s\n", res[i].experience);
      printf("\n");
   }

   return 0;
}