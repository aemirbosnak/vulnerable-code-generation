//FormAI DATASET v1.0 Category: Database querying ; Style: statistical
/* Statistical example program querying a database of student grades */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main(int argc, char **argv)
{
  int rc;
  float mean, median, mode = 0;
  int frequency = 0;
  sqlite3 *db;
  sqlite3_stmt *stmt;

  /* Open the database */
  rc = sqlite3_open("grades.db", &db);
  if(rc != SQLITE_OK) {
    fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  /* Prepare SQL statement */
  rc = sqlite3_prepare_v2(db, "SELECT grade FROM student_grades", -1, &stmt, 0);
  if(rc != SQLITE_OK) {
    fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 1;
  }

  /* Calculate Mean, Median, Mode */
  int count = 0;
  int *grades = NULL;
  while(sqlite3_step(stmt) == SQLITE_ROW) {
    count++;
    grades = realloc(grades, count * sizeof(int));
    grades[count-1] = sqlite3_column_int(stmt, 0);
    mean += grades[count-1];
  }
  mean /= count;

  if(count % 2 == 0) {
    median = (float) (grades[count/2] + grades[(count/2)+1]) / 2;
  } else {
    median = grades[count/2];
  }

  int max_freq = 0;
  for(int i=0; i<count; i++) {
    int freq = 0;
    for(int j=i+1; j<count; j++) {
      if(grades[j] == grades[i]) freq++;
    }
    if(freq > max_freq) {
      mode = grades[i];
      max_freq = freq;
    }
    if(freq == max_freq) {
      if(grades[i] < mode) {
        mode = grades[i];
      }
    }
  }

  /* Print results */
  printf("Total Grades: %d\n", count);
  printf("Mean: %.2f\n", mean);
  printf("Median: %.2f\n", median);
  printf("Mode: %.0f\n", mode);

  /* Clean up */
  sqlite3_finalize(stmt);
  sqlite3_close(db);
  free(grades);

  return 0;
}