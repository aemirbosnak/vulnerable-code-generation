//FormAI DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define BACKUP_FOLDER_NAME "backups"

void createBackup(char* filename);
void restoreBackup(char* backupFilename, char* originalFilename);

int main()
{
   char filename[MAX_FILENAME_LENGTH];
   printf("Enter filename to backup: ");
   scanf("%s", filename);
   createBackup(filename);

   char backupFilename[MAX_FILENAME_LENGTH];
   printf("Enter backup filename to restore: ");
   scanf("%s", backupFilename);

   char originalFilename[MAX_FILENAME_LENGTH];
   printf("Enter original filename to restore to: ");
   scanf("%s", originalFilename);

   restoreBackup(backupFilename, originalFilename);
   return 0;
}

void createBackup(char* filename)
{
   // Create backup folder if it does not exist
   char backupFolderPath[MAX_FILENAME_LENGTH];
   snprintf(backupFolderPath, MAX_FILENAME_LENGTH, "./%s", BACKUP_FOLDER_NAME);
   mkdir(backupFolderPath, 0777);

   // Generate backup filename and open files
   char backupFilename[MAX_FILENAME_LENGTH];
   snprintf(backupFilename, MAX_FILENAME_LENGTH, "./%s/%s.backup", BACKUP_FOLDER_NAME, filename);
   FILE* originalFile = fopen(filename, "rb");
   FILE* backupFile = fopen(backupFilename, "wb");

   // Read original file byte by byte and write to backup file
   int byte;
   while((byte = fgetc(originalFile)) != EOF)
   {
       fputc(byte, backupFile);
   }

   // Close files and report success
   fclose(originalFile);
   fclose(backupFile);
   printf("%s has been backed up to %s\n", filename, backupFilename);
}

void restoreBackup(char* backupFilename, char* originalFilename)
{
   // Open files
   char backupFilePath[MAX_FILENAME_LENGTH];
   snprintf(backupFilePath, MAX_FILENAME_LENGTH, "./%s/%s", BACKUP_FOLDER_NAME, backupFilename);
   FILE* backupFile = fopen(backupFilePath, "rb");
   FILE* originalFile = fopen(originalFilename, "wb");

   // Read backup file byte by byte and write to original file
   int byte;
   while((byte = fgetc(backupFile)) != EOF)
   {
       fputc(byte, originalFile);
   }

   // Close files and report success
   fclose(originalFile);
   fclose(backupFile);
   printf("%s has been restored from %s\n", originalFilename, backupFilename);
}