//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// A simple C program to demonstrate database querying in a statistical style.

// This program will read a database of student grades and perform some basic statistical calculations on the data.

// The database schema is as follows:

// CREATE TABLE students (
//   id INTEGER PRIMARY KEY,
//   name TEXT,
//   grade INTEGER
// );

int main() {
  // Open the database connection.
  sqlite3 *db;
  int rc = sqlite3_open("students.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Prepare the SQL statement to query the database.
  sqlite3_stmt *stmt;
  const char *sql = "SELECT name, grade FROM students";
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Execute the SQL statement.
  int total_grade = 0;
  int count = 0;
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    // Get the student's name and grade.
    const char *name = (const char *)sqlite3_column_text(stmt, 0);
    int grade = sqlite3_column_int(stmt, 1);

    // Add the grade to the total.
    total_grade += grade;

    // Increment the count of students.
    count++;

    // Print the student's name and grade.
    printf("%s: %d\n", name, grade);
  }

  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Error executing statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Calculate the average grade.
  double average_grade = (double)total_grade / count;

  // Print the average grade.
  printf("Average grade: %.2f\n", average_grade);

  // Calculate the standard deviation of the grades.
  double variance = 0;
  sqlite3_reset(stmt);
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    // Get the student's grade.
    int grade = sqlite3_column_int(stmt, 1);

    // Calculate the variance.
    variance += (grade - average_grade) * (grade - average_grade);
  }
  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Error executing statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  double standard_deviation = sqrt(variance / count);

  // Print the standard deviation.
  printf("Standard deviation: %.2f\n", standard_deviation);

  // Close the statement and the database connection.
  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return 0;
}