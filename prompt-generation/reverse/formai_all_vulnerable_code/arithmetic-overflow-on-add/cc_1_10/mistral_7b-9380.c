//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 30
#define MAX_SKILLS_LEN 80
#define MAX_EXP_LEN 100
#define MAX_LINES 10

typedef struct {
 char name[MAX_NAME_LEN];
 char skills[MAX_SKILLS_LEN][MAX_NAME_LEN];
 char experience[MAX_EXP_LEN][MAX_NAME_LEN][3];
 int lines;
} resume_t;

void parse_line(char *line, resume_t *resume) {
 if (sscanf(line, "%s %s %[^:]:%s", resume->name, resume->skills[resume->lines], &resume->experience[resume->lines][0][0]) != 3) {
 strcpy(resume->name, "");
 strcpy(resume->skills[resume->lines], "");
 strcpy(resume->experience[resume->lines][0], "");
 } else {
 resume->lines++;
 }
}

int main(int argc, char **argv) {
 FILE *fp;
 char line[120];
 resume_t my_resume;
 my_resume.lines = 0;

 if (argc != 2) {
 printf("Usage: %s <resume_file>\n", argv[0]);
 return 1;
 }

 if ((fp = fopen(argv[1], "r")) == NULL) {
 printf("Error: Could not open file %s\n", argv[1]);
 return 1;
 }

 while (fgets(line, sizeof(line), fp) != NULL) {
 parse_line(line, &my_resume);
 }

 fclose(fp);

 printf("\nNAME:\n%s\n", my_resume.name);
 printf("\nSKILLS:\n");
 for (int i = 0; i < my_resume.lines; i++) {
 printf("%s\n", my_resume.skills[i]);
 }
 printf("\nEXPERIENCE:\n");
 for (int i = 0; i < my_resume.lines; i++) {
 printf("%s at %s\n%s\n", my_resume.experience[i][0], my_resume.experience[i][1], my_resume.experience[i][2]);
 }

 return 0;
}