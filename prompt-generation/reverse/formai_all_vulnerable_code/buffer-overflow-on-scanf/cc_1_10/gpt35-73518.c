//FormAI DATASET v1.0 Category: File system simulation ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000 

struct Directory {
   char dirName[20]; 
   int dirIndex;  
   int parentIndex; 
   int isEmpty; 
};

struct File {
   char name[20]; 
   int dirIndex;  
   char content[MAX_SIZE]; 
   int size; 
   int isDeleted; 
};

int dIndex = 0;  
int fIndex = 0;  

struct Directory directory[100]; 
struct File file[100]; 


void createDirectory(char *dirName, int parent) {
   int i;

   for(i = 0; i < dIndex; i++) {
      if(!strcmp(directory[i].dirName, dirName) && directory[i].parentIndex == parent) {
         printf("Directory already exists!\n");
         return;
      }
   }

   directory[dIndex].dirIndex = dIndex;  
   strcpy(directory[dIndex].dirName, dirName);
   directory[dIndex].parentIndex = parent;
   directory[dIndex].isEmpty = 0; 
   dIndex++;

   printf("Directory created successfully!\n");
}

void listDirectory(int dirIndex) {
   int i;

   for(i = 0; i < fIndex; i++) {
      if(file[i].dirIndex == dirIndex && !file[i].isDeleted) {
         printf("%s\n", file[i].name);
      }
   }
}

int findDirectory(char *dirName, int parent) {
   int i;

   for(i = 0; i < dIndex; i++) {
      if(!strcmp(directory[i].dirName, dirName) && directory[i].parentIndex == parent) {
         return i;
      }
   }

   return -1;  
}

void createFile(char *fileName, int dirIndex) {
   int i;

   for(i = 0; i < fIndex; i++) {
      if(!strcmp(file[i].name, fileName) && file[i].dirIndex == dirIndex && !file[i].isDeleted) {
         printf("File already exists!\n");
         return;
      }
   }

   strcpy(file[fIndex].name, fileName);
   file[fIndex].dirIndex = dirIndex; 
   file[fIndex].size = 0;
   file[fIndex].isDeleted = 0;
   fIndex++;

   printf("File created successfully!\n");
}

int findFile(char *fileName, int dirIndex) {
   int i;

   for(i = 0; i < fIndex; i++) {
      if(!strcmp(file[i].name, fileName) && file[i].dirIndex == dirIndex && !file[i].isDeleted) {
         return i;
      }
   }

   return -1;
}

void readFile(char *fileName, int dirIndex) {
   int index = findFile(fileName, dirIndex);

   if(index == -1) {
      printf("File not found!\n");
      return;
   }

   printf("Content: %s\n", file[index].content);
}

void writeFile(char *fileName, int dirIndex, char *content) {
   int index = findFile(fileName, dirIndex);

   if(index == -1) {
      printf("File not found!\n");
      return;
   }

   strcpy(file[index].content, content);
   file[index].size = strlen(content);

   printf("Content written successfully!\n");
}

void deleteDirectory(int dirIndex) {
   int i;

   for(i = 0; i < dIndex; i++) {
      if(directory[i].parentIndex == dirIndex && !directory[i].isEmpty) {
         printf("Directory is not empty!\n");
         return;
      }
   }

   directory[dirIndex].isEmpty = 1;

   printf("Directory deleted successfully!\n");
}

void deleteFile(char *fileName, int dirIndex) {
   int index = findFile(fileName, dirIndex);

   if(index == -1) {
      printf("File not found!\n");
      return;
   }

   file[index].isDeleted = 1;

   printf("File deleted successfully!\n");
}

int main() {
   char command[20];
   char arg1[20];
   char arg2[20];

   int parent, dirIndex;

   while(1) {
      printf("Enter the command: ");
      scanf("%s", command);

      if(!strcmp(command, "exit")) {
         break;
      }

      if(!strcmp(command, "mkdir")) {
         scanf("%s %s", arg1, arg2);

         if(!strcmp(arg1, "-p")) {
            arg1[0] = '\0';
            strcat(arg1, arg2);
            arg2[0] = '\0';
            scanf("%s", arg2);

            parent = 0;
            char *token = strtok(arg1, "/");

            while(token != NULL) {
               dirIndex = findDirectory(token, parent);

               if(dirIndex == -1) {
                  createDirectory(token, parent);
                  dirIndex = dIndex - 1;  
               }

               token = strtok(NULL, "/");
               parent = dirIndex;
            }

            createDirectory(arg2, parent);
         } else {
            dirIndex = findDirectory(arg1, 0);

            if(dirIndex == -1) {
               printf("Parent directory not found!\n");
            } else {
               createDirectory(arg2, dirIndex);
            }
         }
      }

      if(!strcmp(command, "ls")) {
         scanf("%s", arg1);

         dirIndex = findDirectory(arg1, 0);

         if(dirIndex == -1) {
            printf("Directory not found!\n");
         } else {
            listDirectory(dirIndex);
         }
      }

      if(!strcmp(command, "touch")) {
         scanf("%s %s", arg1, arg2);

         dirIndex = findDirectory(arg1, 0);

         if(dirIndex == -1) {
            printf("Directory not found!\n");
         } else {
            createFile(arg2, dirIndex);
         }
      }

      if(!strcmp(command, "cat")) {
         scanf("%s %s", arg1, arg2);

         dirIndex = findDirectory(arg1, 0);

         if(dirIndex == -1) {
            printf("Directory not found!\n");
         } else {
            readFile(arg2, dirIndex);
         }
      }

      if(!strcmp(command, "echo")) {
         scanf("%s %s", arg1, arg2);

         dirIndex = findDirectory(arg1, 0);

         if(dirIndex == -1) {
            printf("Directory not found!\n");
         } else {
            char temp[MAX_SIZE] = "";

            while(1) {
               char str[MAX_SIZE];
               scanf("%s", str);

               if(!strcmp(str, ">")) {
                  break;
               }

               strcat(temp, str);
               strcat(temp, " ");
            }

            writeFile(arg2, dirIndex, temp);
         }
      }

      if(!strcmp(command, "rmdir")) {
         scanf("%s", arg1);

         dirIndex = findDirectory(arg1, 0);

         if(dirIndex == -1) {
            printf("Directory not found!\n");
         } else {
            deleteDirectory(dirIndex);
         }
      }

      if(!strcmp(command, "rm")) {
         scanf("%s %s", arg1, arg2);

         dirIndex = findDirectory(arg1, 0);

         if(dirIndex == -1) {
            printf("Directory not found!\n");
         } else {
            deleteFile(arg2, dirIndex);
         }
      }
   }

   return 0;
}