//FormAI DATASET v1.0 Category: File Synchronizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>

void synchronize(char* dirPath1, char* dirPath2){
  DIR *dir1, *dir2;
  struct dirent *dp1, *dp2;
  struct stat statbuf1, statbuf2;
  char filePath1[256], filePath2[256];

  // open the directories dirPath1 and dirPath2
  dir1 = opendir(dirPath1);
  dir2 = opendir(dirPath2);

  if(dir1 == NULL){
    printf("Error opening directory: %s", dirPath1);
    return;
  }

  if(dir2 == NULL){
    printf("Error opening directory: %s", dirPath2);
    return;
  }

  // iterate over all the files and directories in dirPath1
  while((dp1 = readdir(dir1)) != NULL){

    // ignore . and .. directories
    if(strcmp(dp1->d_name, ".") == 0 || strcmp(dp1->d_name, "..") == 0){
      continue;
    }

    // create the full file path1
    sprintf(filePath1, "%s/%s", dirPath1, dp1->d_name);

    // get the file status information for the file at filePath1
    if(stat(filePath1, &statbuf1) == -1){
      printf("Error getting file information: %s", filePath1);
      continue;
    }

    // iterate over all files and directories in dirPath2
    while((dp2 = readdir(dir2)) != NULL){

      // ignore . and .. directories
      if(strcmp(dp2->d_name, ".") == 0 || strcmp(dp2->d_name, "..") == 0){
        continue;
      }

      // create the full file path2
      sprintf(filePath2, "%s/%s", dirPath2, dp2->d_name);

      // get the file status information for the file at filePath2
      if(stat(filePath2, &statbuf2) == -1){
        printf("Error getting file information: %s", filePath2);
        continue;
      }

      // check if the file names and sizes match
      if(strcmp(dp1->d_name, dp2->d_name) == 0 && statbuf1.st_size == statbuf2.st_size){

        // check if the files are the same
        FILE* file1 = fopen(filePath1, "rb");
        FILE* file2 = fopen(filePath2, "rb");
        int c1, c2;
        bool filesAreEqual = true;

        while((c1 = getc(file1)) != EOF && (c2 = getc(file2)) != EOF){
          if(c1 != c2){
            filesAreEqual = false;
            break;
          }
        }

        if(filesAreEqual){
          printf("File %s is already synchronized\n", filePath1);
          fclose(file1);
          fclose(file2);
          break;
        }

        // if the files do not match, replace the file in dirPath2 with the one in dirPath1
        printf("Replacing file %s in %s with file from %s\n", dp2->d_name, dirPath2, dirPath1);
        fclose(file1);
        fclose(file2);
        remove(filePath2);
        rename(filePath1, filePath2);
        break;

      }

    }

    // if the file is not found in dirPath2, create it
    if(dp2 == NULL){
      printf("File %s is not found in %s, creating it...\n", dp1->d_name, dirPath2);
      char cmd[256];
      sprintf(cmd, "cp %s %s", filePath1, dirPath2);
      system(cmd);
    }

    // go back to the beginning of dirPath2
    rewinddir(dir2);

  }

  // iterate over all the files in dirPath2
  while((dp2 = readdir(dir2)) != NULL){

    // ignore . and .. directories
    if(strcmp(dp2->d_name, ".") == 0 || strcmp(dp2->d_name, "..") == 0){
      continue;
    }

    // create the full file path2
    sprintf(filePath2, "%s/%s", dirPath2, dp2->d_name);

    // get the file status information for the file at filePath2
    if(stat(filePath2, &statbuf2) == -1){
      printf("Error getting file information: %s", filePath2);
      continue;
    }

    // iterate over all files and directories in dirPath1 to check if the file is already synchronized
    bool fileIsSynchronized = false;

    while((dp1 = readdir(dir1)) != NULL){

      // ignore . and .. directories
      if(strcmp(dp1->d_name, ".") == 0 || strcmp(dp1->d_name, "..") == 0){
        continue;
      }

      // create the full file path1
      sprintf(filePath1, "%s/%s", dirPath1, dp1->d_name);

      // get the file status information for the file at filePath1
      if(stat(filePath1, &statbuf1) == -1){
        printf("Error getting file information: %s", filePath1);
        continue;
      }

      // check if the file names and sizes match
      if(strcmp(dp1->d_name, dp2->d_name) == 0 && statbuf1.st_size == statbuf2.st_size){

        // check if the files are the same
        FILE* file1 = fopen(filePath1, "rb");
        FILE* file2 = fopen(filePath2, "rb");
        int c1, c2;
        bool filesAreEqual = true;

        while((c1 = getc(file1)) != EOF && (c2 = getc(file2)) != EOF){
          if(c1 != c2){
            filesAreEqual = false;
            break;
          }
        }

        if(filesAreEqual){
          fileIsSynchronized = true;
          fclose(file1);
          fclose(file2);
          break;
        }

        fclose(file1);
        fclose(file2);
        break;

      }

    }

    // if the file is not found in dirPath1, delete it from dirPath2
    if(dp1 == NULL && !fileIsSynchronized){
      printf("Deleting file %s from %s\n", dp2->d_name, dirPath2);
      remove(filePath2);
    }

    // go back to the beginning of dirPath1
    rewinddir(dir1);

  }

  // close the directories
  closedir(dir1);
  closedir(dir2);

}

int main(int argc, char** argv){
  if(argc != 3){
    printf("Usage: ./synchronizer dir1 dir2\n");
    return 1;
  }
  printf("Synchronizing %s and %s...\n", argv[1], argv[2]);
  synchronize(argv[1], argv[2]);
  return 0;
}